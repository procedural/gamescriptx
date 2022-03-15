struct CameraMatrices {
  matrix<float, 4, 4> viewProj;
  matrix<float, 4, 4> viewProjInv;
};

struct LightMatrices {
  matrix<float, 4, 4> viewProj;
  matrix<float, 4, 4> viewProjInv;
};

StructuredBuffer<CameraMatrices> camera:           register(t0, space0);
StructuredBuffer<LightMatrices>  light:            register(t0, space1);
Texture2D                        shadowMap:        register(t0, space2);
SamplerState                     shadowMapSampler: register(s0, space3);
ByteAddressBuffer                vertices:         register(t0, space4);

struct interpolated {
  float4 position:    SV_Position;
  float3 worldNormal: WorldNormal;
  float3 worldPos:    WorldPos;
};

struct render {
  float4 color: SV_Target0;
};

interpolated VSMain(uint vid: SV_VertexID, uint iid: SV_InstanceID) {
  float4 position;
  float4 normal;
  position.x = asfloat(vertices.Load((vid * 6 + 0) * 4));
  position.y = asfloat(vertices.Load((vid * 6 + 1) * 4));
  position.z = asfloat(vertices.Load((vid * 6 + 2) * 4));
  position.w = 0;
  normal.x   = asfloat(vertices.Load((vid * 6 + 3) * 4));
  normal.y   = asfloat(vertices.Load((vid * 6 + 4) * 4));
  normal.z   = asfloat(vertices.Load((vid * 6 + 5) * 4));
  normal.w   = 0;
  interpolated output;
  output.worldNormal = normal.xyz;
  output.worldPos = position.xyz;
  output.position = mul(camera[0].viewProj, float4(output.worldPos.x, output.worldPos.y, output.worldPos.z, 1.0f));
  output.position.y = -output.position.y;
  return output;
}

render PSMain(interpolated input) {
  float4 shadowMapCoords = mul(light[0].viewProj, float4(input.worldPos.x, input.worldPos.y, input.worldPos.z, 1.0f));
  shadowMapCoords = (shadowMapCoords / shadowMapCoords.w);
  shadowMapCoords.xy = shadowMapCoords.xy * 0.5f + 0.5f;
  float shadowMapDepth = shadowMap.Sample(shadowMapSampler, shadowMapCoords.xy).x;
  float shadowAttenuation = (shadowMapDepth < shadowMapCoords.z) ? 0.25f : 1.0f;
  float4 lightPos = mul(light[0].viewProjInv, float4(0, 0, -1, 1));
  lightPos /= lightPos.w;
  float3 lightDir = normalize(lightPos.xyz - input.worldPos);
  float nDotL = max(0.0f, dot(lightDir, input.worldNormal));
  float diffuse = nDotL * shadowAttenuation;
  render output;
  output.color = float4(diffuse, diffuse, diffuse, diffuse);
  return output;
}

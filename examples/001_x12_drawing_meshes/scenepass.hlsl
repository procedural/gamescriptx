struct CameraMatrices {
  matrix<float, 4, 4> viewProj;
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
  {
    float a = camera[0].viewProj._m00;
    float b = camera[0].viewProj._m01;
    float c = camera[0].viewProj._m02;
    float d = camera[0].viewProj._m03;
    float e = camera[0].viewProj._m10;
    float f = camera[0].viewProj._m11;
    float g = camera[0].viewProj._m12;
    float h = camera[0].viewProj._m13;
    float i = camera[0].viewProj._m20;
    float j = camera[0].viewProj._m21;
    float k = camera[0].viewProj._m22;
    float l = camera[0].viewProj._m23;
    float m = camera[0].viewProj._m30;
    float n = camera[0].viewProj._m31;
    float o = camera[0].viewProj._m32;
    float p = camera[0].viewProj._m33;
    
    float x = output.worldPos.x;
    float y = output.worldPos.y;
    float z = output.worldPos.z;
    float w = 1.0f;
    
    output.position.x = x*a + y*b + z*c + w*d;
    output.position.y = x*e + y*f + z*g + w*h;
    output.position.z = x*i + y*j + z*k + w*l;
    output.position.w = x*m + y*n + z*o + w*p;
    
    //output.position = mul(camera[0].viewProj, float4(output.worldPos.x, output.worldPos.y, output.worldPos.z, 1.0f));
  }
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

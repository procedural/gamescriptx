struct LightMatrices {
  matrix<float, 4, 4> viewProj;
  matrix<float, 4, 4> viewProjInv;
};

StructuredBuffer<LightMatrices> light:       register(t0, space1);
ByteAddressBuffer               in_Vertices: register(t0, space4);

struct interpolated {
  float4 position: SV_Position;
};

interpolated VSMain(uint vid: SV_VertexID, uint iid: SV_InstanceID) {
  float4 position;
  position.x = asfloat(in_Vertices.Load((vid * 6 + 0) * 4));
  position.y = asfloat(in_Vertices.Load((vid * 6 + 1) * 4));
  position.z = asfloat(in_Vertices.Load((vid * 6 + 2) * 4));
  position.w = 1.0f;
  interpolated output;
  output.position = mul(light[0].viewProj, position);
  output.position.y = -output.position.y;
  return output;
}

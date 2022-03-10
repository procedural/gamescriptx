struct interpolated {
  float4 position: SV_Position;
};

struct render {
  float4 color: SV_Target0;
};

interpolated VSMain(uint vid: SV_VertexID, uint iid: SV_InstanceID) {
  interpolated output;
  output.position = float4(vid == 1 ? 3 : -1, vid == 2 ? 3 : -1, 0.5, 1);
  return output;
}

render PSMain(interpolated input) {
  render output;
  output.color = float4(input.position.x / 1800.0, 0, input.position.y / 900.0, 1);
  return output;
}
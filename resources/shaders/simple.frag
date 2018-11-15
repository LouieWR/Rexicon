uniform sampler2D in_UV;

varying vec2 ex_UVCoord;

void main()
{
  vec4 tex = texture2D(in_UV, ex_UVCoord);
  gl_FragColor = tex;
}

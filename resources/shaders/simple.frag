uniform sampler2D in_Texture;
uniform mat4 in_Model;

uniform struct LightSource {
   vec4 pos;
   vec4 col;
} in_Light;

uniform vec4 in_Ambience;

varying vec2 ex_TexCoord;
varying vec3 ex_Position;
varying vec3 ex_Normal;

void main()
{
	mat3 nmlMat = transpose(inverse(mat3(in_Model)));
	vec3 nml = normalize(nmlMat * ex_Normal);

	vec3 lightDir = in_Light.pos - ex_Position;

	float intensity = dot(nml, lightDir) / (length(lightDir) * length(nml));
	intensity = clamp(intensity, 0, 1);

	vec4 col = texture2D(in_Texture, ex_TexCoord);
	gl_FragColor = vec4(intensity * in_Light.col * col.rgb + in_Ambience, col.a);
}

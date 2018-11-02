#version 430 core

// Input per-fragment data
// These must correspond to the varying outputs from the vertex shader
in vec3 vNormalV;
in vec3 eyeSpaceLightPosV;
in vec3 eyeSpaceVertPosV;
in vec2 texCoord;
in vec3 fPos;


// Input uniform data - these have values that will be the same for every fragment
uniform vec3 lightColour = {0.9,0.9,1};
uniform vec3 emissiveColour = {0,0,0};
uniform vec3 ambientColour  = {0.6f,0.6f,0.7f};
uniform vec3 diffuseColour  = {1.0f,1.0f,1.0f};
uniform vec3 specularColour = {1.0f,1.0f,1.0f};
uniform float shininess     = 50.0f;
uniform float alpha         = 1.0f;
uniform vec3 view;

// The output of the fragment shader is the fragment's colour
out vec4 fragColour;

// This is another input to allow us to access a texture
uniform sampler2D tex1;


void main()
{
	// Calculate the direction from the sample position to the light
	vec3 lightDir = normalize( eyeSpaceLightPosV - eyeSpaceVertPosV );
	// Ensure the normal is a unit vector
	vec3 normal = normalize( vNormalV );
	// Direction from eye to sample point
	vec3 eyeDir = normalize( -eyeSpaceVertPosV );
	// Vector half way between one to eye and one to light
	vec3 halfVec = normalize( eyeDir + lightDir );

	// Retrieve colour from texture
	vec3 texColour = vec3(texture(tex1,vec2(texCoord.x,1-texCoord.y)));
	// Calculate diffuse lighting
	vec3 diffuse = diffuseColour * lightColour * max( dot( normal, lightDir ), 0);
	
	// Put specular lighting code here!
	float specularFactor = 1.0f;
	vec3 vDir = normalize(view - fPos);
	vec3 rDir = reflect(-lightDir, normal);
	float specularFloat = pow(max(dot(vDir, rDir), 0.0), 32);
	vec3 specular = specularFactor * specularFloat * lightColour;

	// Final colour uses the texture colour for all components
	// If you want a separate texture for specular you will need to change this
	fragColour = vec4( emissiveColour + texColour*(ambientColour + diffuse + specular), alpha);
}

#version 330

in vec2 InterpolatedTexCoord;
in vec3 InterpolatedColor;
in vec3 InterpolatedNormal;
in vec3 PixelPosition;

out vec4 FragColor;

uniform sampler2D DiffuseTexture;
uniform sampler2D DiffuseTexture1;
uniform vec3 LightColor;
uniform vec3 LightPosition;
uniform vec3 CameraPosition;



void main()
{
	vec3 ambient = 0.1f * LightColor;

	
	vec3 L = LightPosition - PixelPosition;
	L = normalize(L);
	vec3 diffuse = dot(InterpolatedNormal, L) * LightColor;

	vec3 R = reflect(-L, InterpolatedNormal);
	vec3 V = CameraPosition - PixelPosition;
	V= normalize(V);
	float h = dot(V, R);
	
	//fix
	if (h<0){
		h = 0 ;
	}

	vec3 specular = 0.5f * pow(h, 32) * LightColor;

	vec4 phong = vec4((ambient + diffuse + specular), 1.0f) * mix(texture2D(DiffuseTexture, InterpolatedTexCoord), texture2D(DiffuseTexture1, InterpolatedTexCoord), 0.5f);
	
	FragColor = phong;
	
	
}

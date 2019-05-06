#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 normal;

out vec3 vertexPosition;
out vec2 vertexTexCoord;
out vec3 vertexNormal;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_proj;

void main()
{
    vertexPosition = vec3(u_model * vec4(position, 1.0f));
    vertexTexCoord = texCoord;
    vertexNormal = mat3(transpose(inverse(u_model))) * normal;

    gl_Position = u_proj * u_view * u_model * vec4(position, 1.0f);
}


#shader fragment
#version 330 core

#define NR_DIRECTIONAL_LIGHTS 32
#define NR_POINT_LIGHTS 32
#define NR_SPOT_LIGHTS 32

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct DirectionalLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight {
    vec3 position;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct SpotLight {
    vec3  position;
    vec3  direction;
    float cutOff;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 vertexPosition;
in vec2 vertexTexCoord;
in vec3 vertexNormal;

uniform vec3 u_color;
uniform sampler2D u_texture;

uniform Material u_material;

uniform DirectionalLight directionalLights[NR_DIRECTIONAL_LIGHTS];
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform SpotLight spotLights[NR_SPOT_LIGHTS];

uniform vec3 u_viewPos;

vec3 calculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir);

void main()
{
    vec3 normal = normalize(vertexNormal);
    vec3 viewDir = normalize(u_viewPos - vertexPosition);

    vec3 result = calculateDirectionalLight(directionalLights[0], normal, viewDir) * u_color;

    gl_FragColor = vec4(result, 1.0f) * texture(u_texture, vertexTexCoord) * vec4(u_color, 1.0f);
}

vec3 calculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir)
{
    // Ambient light
    vec3 ambient = light.ambient * u_material.diffuse;

    // Diffuse light
    vec3 lightDir = normalize(-light.direction);
    float diff = max(dot(normal, lightDir), 0.0f);
    vec3 diffuse = light.diffuse * diff * u_material.diffuse;

    // Specular light
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0f), u_material.shininess);
    vec3 specular = light.specular * spec * u_material.specular;

    return (ambient + diffuse + specular);
}
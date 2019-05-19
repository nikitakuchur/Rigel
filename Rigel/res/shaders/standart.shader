#shader vertex
#version 330 core

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec2 a_texCoord;
layout(location = 2) in vec3 a_normal;

out vec3 v_fragPos;
out vec2 v_texCoord;
out vec3 v_normal;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_proj;

void main()
{
    v_fragPos = vec3(u_model * vec4(a_position, 1.0f));
    v_texCoord = a_texCoord;
    v_normal = mat3(transpose(inverse(u_model))) * a_normal;

    gl_Position = u_proj * u_view * u_model * vec4(a_position, 1.0f);
}


#shader fragment
#version 330 core

#define NR_DIRECTIONAL_LIGHTS 32
#define NR_POINT_LIGHTS 32
#define NR_SPOT_LIGHTS 32

struct Material {
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
    float outerCutOff;

    float constant;
    float linear;
    float quadratic;
    
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 v_fragPos;
in vec2 v_texCoord;
in vec3 v_normal;

uniform vec3 u_color;
uniform sampler2D u_texture;

uniform Material u_material;

uniform int u_numDirectionalLights;
uniform DirectionalLight u_directionalLights[NR_DIRECTIONAL_LIGHTS];

uniform int u_numPointLights;
uniform PointLight u_pointLights[NR_POINT_LIGHTS];

uniform int u_numSpotLights;
uniform SpotLight u_spotLights[NR_SPOT_LIGHTS];

uniform vec3 u_viewPos;

vec3 calculateDirectionalLight(DirectionalLight light, vec3 normal, vec3 viewDir);
vec3 calculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 calculateSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
    vec3 normal = normalize(v_normal);
    vec3 viewDir = normalize(u_viewPos - v_fragPos);

    vec3 result = vec3(0);
    for (int i = 0; i < u_numDirectionalLights; i++)
        result += calculateDirectionalLight(u_directionalLights[0], normal, viewDir) * u_color;

    for (int i = 0; i < u_numPointLights; i++)
        result += calculatePointLight(u_pointLights[i], normal, v_fragPos, viewDir) * u_color;

    for (int i = 0; i < u_numSpotLights; i++)
        result += calculateSpotLight(u_spotLights[i], normal, v_fragPos, viewDir) * u_color;

    gl_FragColor = vec4(result, 1.0f) * texture(u_texture, v_texCoord) * vec4(u_color, 1.0f);
}

// Calculates the color when using a directional light
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

// Calculates the color when using a point light
vec3 calculatePointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    // Ambient light
    vec3 ambient = light.ambient * u_material.diffuse;

    // Diffuse light
    vec3 lightDir = normalize(light.position - fragPos);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * u_material.diffuse;

    // Specular light
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), u_material.shininess);
    vec3 specular = light.specular * spec * u_material.specular;

    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return (ambient + diffuse + specular);
}

// Calculates the color when using a spot light
vec3 calculateSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    // Ambient light
    vec3 ambient = light.ambient * u_material.diffuse;

    // Diffuse light
    vec3 lightDir = normalize(light.position - fragPos);
    float diff = max(dot(normal, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * u_material.diffuse;

    // Specular light
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), u_material.shininess);
    vec3 specular = light.specular * spec * u_material.specular;

    // Attenuation
    float distance = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    // Spot light intensity
    float theta = dot(lightDir, normalize(-light.direction));
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

    ambient *= attenuation * intensity;
    diffuse *= attenuation * intensity;
    specular *= attenuation * intensity;

    return (ambient + diffuse + specular);
}
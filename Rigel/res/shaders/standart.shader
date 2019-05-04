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
    gl_Position = u_proj * u_view * u_model * vec4(position, 1.0f);

    vertexPosition = vec3(u_model * vec4(position, 1.0f));
    vertexTexCoord = texCoord;
    vertexNormal = mat3(transpose(inverse(u_model))) * normal;
}


#shader fragment
#version 330 core

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 vertexPosition;
in vec2 vertexTexCoord;
in vec3 vertexNormal;

uniform sampler2D u_texture;

uniform vec3 u_viewPos;
uniform Material u_material;
uniform Light u_light;

void main()
{
    // Ambient light
    vec3 ambient = u_light.ambient * u_material.ambient;

    // Diffuse light
    vec3 normal = normalize(vertexNormal);
    vec3 lightDir = normalize(u_light.position - vertexPosition);
    float diff = max(dot(normal, lightDir), 0.0f);
    vec3 diffuse = u_light.diffuse * (diff * u_material.diffuse);

    // Specular light
    vec3 viewDir = normalize(u_viewPos - vertexPosition);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0f), u_material.shininess);
    vec3 specular = u_light.specular * (spec * u_material.specular);

    vec3 result = ambient + diffuse + specular;
    gl_FragColor = vec4(result, 1.0f) * texture(u_texture, vertexTexCoord);
}
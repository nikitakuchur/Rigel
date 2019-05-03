#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 normal;

out vec3 v_position;
out vec2 v_texCoord;
out vec3 v_normal;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_proj;

void main()
{
    gl_Position = u_proj * u_view * u_model * vec4(position, 1.0f);

    v_position = vec3(u_model * vec4(position, 1.0f));
    v_texCoord = texCoord;
    v_normal = mat3(transpose(inverse(u_model))) * normal;
}


#shader fragment
#version 330 core

in vec3 v_position;
in vec2 v_texCoord;
in vec3 v_normal;

uniform sampler2D u_texture;

uniform vec3 u_lightPos;
uniform vec3 u_viewPos;
uniform vec3 u_lightColor;
uniform vec3 u_objectColor;

void main()
{
    // Ambient light
    float ambientStrength = 0.1f;
    vec3 ambientLight = ambientStrength * u_lightColor;

    // Diffuse light
    vec3 norm = normalize(v_normal);
    vec3 lightDir = normalize(u_lightPos - v_position);
    float diffuse = max(dot(norm, lightDir), 0.0f);
    vec3 diffuseLight = diffuse * u_lightColor;

    // Specular light
    float specularStrength = 0.5f;
    vec3 viewDir = normalize(u_viewPos - v_position);
    vec3 reflectDir = reflect(-lightDir, norm);
    float specular = pow(max(dot(viewDir, reflectDir), 0.0f), 32);
    vec3 specularLight = specularStrength * specular * u_lightColor;

    vec3 result = (ambientLight + diffuseLight + specularLight) * u_objectColor;
    gl_FragColor = vec4(result, 1.0f) * texture(u_texture, v_texCoord);
}
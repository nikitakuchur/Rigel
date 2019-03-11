#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0f);
    v_texCoord = texCoord;
}

#shader fragment
#version 330 core

in vec2 v_texCoord;

uniform sampler2D u_texture;

void main()
{
    vec4 texColor = texture(u_texture, v_texCoord);
    gl_FragColor = texColor;
}
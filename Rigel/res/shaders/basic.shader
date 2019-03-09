#shader vertex
#version 330 core

layout(location = 0) in vec2 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_texCoord;

void main()
{
    gl_Position = vec4(position, 0.0, 1.0);
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
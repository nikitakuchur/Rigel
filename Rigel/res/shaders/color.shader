#shader vertex
#version 330 core

layout(location = 0) in vec3 a_position;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_proj;

void main()
{
    gl_Position = u_proj * u_view * u_model * vec4(a_position, 1.0f);
}


#shader fragment
#version 330 core

uniform vec3 u_color;

void main()
{
    gl_FragColor = vec4(u_color, 1.0f);
}
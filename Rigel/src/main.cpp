#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

#include "Shader.h"
#include "Renderer.h"
#include "Texture.h"

int main()
{
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        std::cout << "Error: " << glewGetErrorString(err) << std::endl;
        glfwTerminate();
        return -1;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glm::mat4 proj = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, -1.0f, 1.0f);

    float vertices[] = {
        100.0f, 100.0f, 0.0f, 0.0f,
        500.0f, 100.0f, 1.0f, 0.0f,
        500.0f, 500.0f, 1.0f, 1.0f,
        100.0f, 500.0f, 0.0f, 1.0f
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    VertexArray va;
    VertexBuffer vb(vertices, sizeof(vertices));

    VertexBufferLayout layout;
    layout.push(GL_FLOAT, 2, false);
    layout.push(GL_FLOAT, 2, false);
    va.addBuffer(vb, layout);

    IndexBuffer ib(indices, 6);

    Shader shader("res/shaders/basic.shader");
    shader.bind();
    shader.setUniformMat4f("u_mvp", proj);

    Texture texture("res/textures/default.png");
    texture.bind();
    shader.setUniform1i("u_texture", 0);

    va.unbind();
    vb.unbind();
    ib.unbind();
    shader.unbind();

    Renderer renderer;

    while (!glfwWindowShouldClose(window))
    {
        renderer.clear();
        shader.bind();
        renderer.draw(va, ib, shader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
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
#include "Camera.h"
#include "Player.h"

const int width = 800;
const int height = 600;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main()
{
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    unsigned int err = glewInit();
    if (err != GLEW_OK)
    {
        std::cout << "Error: " << glewGetErrorString(err) << std::endl;
        glfwTerminate();
        return -1;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Player player;
    player.setPosition(glm::vec3(0.0f, 0.0f, -1.0f));

    float vertices[] = {
        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f,    0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 0.0f,    0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 1.0f,    0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,    0.0f, 1.0f,    0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f,    0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,    1.0f, 0.0f,    0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 1.0f,    0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 1.0f,    0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f,    1.0f, 0.0f,   -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,    1.0f, 1.0f,   -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,    0.0f, 1.0f,   -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f,   -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,    1.0f, 0.0f,    1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 1.0f,    1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,    0.0f, 1.0f,    1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,    0.0f, 0.0f,    1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,    0.0f, 1.0f,    0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,    1.0f, 1.0f,    0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,    1.0f, 0.0f,    0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,    0.0f, 0.0f,    0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,    0.0f, 1.0f,    0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,    1.0f, 1.0f,    0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,    1.0f, 0.0f,    0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,    0.0f, 0.0f,    0.0f,  1.0f,  0.0f
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0,

        4, 5, 6,
        6, 7, 4,

        8, 9, 10,
        10, 11, 8,

        12, 13, 14,
        14, 15, 12,

        16, 17, 18,
        18, 19, 16,

        20, 21, 22,
        22, 23, 20
    };

    VertexArray va;
    VertexBuffer vb(vertices, sizeof(vertices));

    VertexBufferLayout layout;
    layout.push(GL_FLOAT, 3, false);
    layout.push(GL_FLOAT, 2, false);
    layout.push(GL_FLOAT, 3, false);
    va.addBuffer(vb, layout);

    IndexBuffer ib(indices, 36);

    // Box shader
    Shader boxShader("res/shaders/standart.shader");
    boxShader.bind();

    Texture pixelTexture("res/textures/pixel.png");
    Texture boxTexture("res/textures/box.png");
    pixelTexture.bind(0);
    boxTexture.bind(1);

    // Material
    boxShader.setUniform3f("u_material.ambient", 0.1f, 0.1f, 0.1f);
    boxShader.setUniform3f("u_material.diffuse", 1.0f, 1.0f, 1.0f);
    boxShader.setUniform3f("u_material.specular", 1.0f, 1.0f, 1.0f);
    boxShader.setUniform1f("u_material.shininess", 32.0f);

    // Light
    boxShader.setUniform3f("directionalLights[0].direction", 0.4f, -1.0f, -1.0f);
    boxShader.setUniform3f("directionalLights[0].ambient", 0.1f, 0.1f, 0.1f);
    boxShader.setUniform3f("directionalLights[0].diffuse", 1.0f, 1.0f, 1.0f);
    boxShader.setUniform3f("directionalLights[0].specular", 1.0f, 1.0f, 1.0f);

    boxShader.unbind();

    va.unbind();
    vb.unbind();
    ib.unbind();

    Renderer renderer;

    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Exit
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);

        player.update(window, deltaTime);
        renderer.clear();

        boxShader.bind();
        glm::vec3 cameraPosition = player.getCamera().getPosition();
        boxShader.setUniform3f("u_viewPos", cameraPosition.x, cameraPosition.y, cameraPosition.z);

        glm::mat4 view = player.getCamera().getViewMatrix();
        boxShader.setUniformMat4f("u_view", view);

        glm::mat4 proj = player.getCamera().getProjectionMatrix();
        boxShader.setUniformMat4f("u_proj", proj);

        boxShader.setUniform1i("u_texture", 1);
        boxShader.setUniform3f("u_color", 1.0f, 1.0f, 1.0f);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 3.0f));
        boxShader.setUniformMat4f("u_model", model);
        renderer.drawElements(va, ib, boxShader);

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(2.0f, 0.0f, 3.0f));
        boxShader.setUniformMat4f("u_model", model);
        renderer.drawElements(va, ib, boxShader);

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-2.0f, 0.0f, 3.0f));
        boxShader.setUniformMat4f("u_model", model);
        renderer.drawElements(va, ib, boxShader);

        boxShader.setUniform1i("u_texture", 0);
        boxShader.setUniform3f("u_color", 0.6f, 0.6f, 0.6f);

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, -1.0f, 3.0f));
        model = glm::scale(model, glm::vec3(11.0f, 1.0f, 11.0f));
        boxShader.setUniformMat4f("u_model", model);
        renderer.drawElements(va, ib, boxShader);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
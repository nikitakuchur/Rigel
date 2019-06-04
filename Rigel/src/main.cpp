#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

#include "glutils/Renderer.h"
#include "StaticShader.h"
#include "Material.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Texture.h"
#include "Camera.h"
#include "Spectator.h"

const int WIDTH = 1600;
const int HEIGHT = 900;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main()
{
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

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

    Spectator spectator;
    spectator.setPosition(glm::vec3(0.0f, 0.0f, -1.0f));

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

    rigel::VertexArray va;
    rigel::VertexBuffer vb(vertices, sizeof(vertices));

    rigel::VertexBufferLayout layout;
    layout.push(GL_FLOAT, 3, false);
    layout.push(GL_FLOAT, 2, false);
    layout.push(GL_FLOAT, 3, false);
    va.addBuffer(vb, layout);

    rigel::IndexBuffer ib(indices, 36);

    // Materials
    rigel::Material boxMaterial;
    rigel::Material planeMaterial;

    planeMaterial.setAmbient(glm::vec3(0.3f, 0.3f, 0.3f));
    planeMaterial.setDiffuse(glm::vec3(0.3f, 0.3f, 0.3f));
    planeMaterial.setSpecular(glm::vec3(0.3f, 0.3f, 0.3f));

    // Lights
    rigel::DirectionalLight directionalLights[1];
    rigel::PointLight pointLights[3];
    rigel::SpotLight spotLights[1];

    pointLights[0].setPosition(glm::vec3(-20.0f, 2.0f, 0.0f));
    pointLights[1].setPosition(glm::vec3(0.0f, 2.0f, 0.0f));
    pointLights[2].setPosition(glm::vec3(20.0f, 2.0f, 0.0f));

    spotLights[0].setPosition(glm::vec3(0.0f, 2.0f, 10.0f));
    spotLights[0].setDirection(glm::vec3(0.0f, -1.0f, -2.0f));

    // Shader
    rigel::StaticShader shader;
    shader.bind();

    rigel::Texture pixelTexture("res/textures/pixel.png");
    rigel::Texture boxTexture("res/textures/box.png");
    pixelTexture.bind(0);
    boxTexture.bind(1);

    shader.setMaterial(boxMaterial);
    shader.setDirectionalLights(directionalLights, 1);
    shader.setPointLights(pointLights, 3);
    shader.setSpotLights(spotLights, 1);

    shader.unbind();

    va.unbind();
    vb.unbind();
    ib.unbind();

    rigel::Renderer renderer;

    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Exit
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GL_TRUE);

        spectator.update(window, deltaTime);
        renderer.clear();

        shader.bind();
        glm::vec3 cameraPosition = spectator.getCamera().getPosition();
        shader.setViewPosition(cameraPosition);

        glm::mat4 view = spectator.getCamera().getViewMatrix();
        shader.setViewMatrix(view);

        glm::mat4 proj = spectator.getCamera().getProjectionMatrix();
        shader.setProjectionMatrix(proj);

        shader.setTexture(1);
        shader.setMaterial(boxMaterial);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 3.0f));
        shader.setModelMatrix(model);
        renderer.drawElements(va, ib, shader);

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(2.0f, 0.0f, 3.0f));
        shader.setModelMatrix(model);
        renderer.drawElements(va, ib, shader);

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-2.0f, 0.0f, 3.0f));
        shader.setModelMatrix(model);
        renderer.drawElements(va, ib, shader);

        shader.setTexture(0);
        shader.setMaterial(planeMaterial);

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, -1.0f, 3.0f));
        model = glm::scale(model, glm::vec3(100.0f, 1.0f, 100.0f));
        shader.setModelMatrix(model);
        renderer.drawElements(va, ib, shader);

        shader.unbind();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
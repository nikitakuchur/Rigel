#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <vector>

#include "Renderer.h"
#include "StandardShader.h"
#include "Material.h"
#include "PointLight.h"
#include "Texture.h"
#include "Spectator.h"

const int WIDTH = 800;
const int HEIGHT = 600;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main() {
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Demo", nullptr, nullptr);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    std::cout << glGetString(GL_VERSION) << std::endl;

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    rigel::Spectator spectator;
    spectator.setPosition(glm::vec3(0.0f, 1.0f, 0.0f));

    // Box
    std::vector<rigel::Vertex> boxVertices{
            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
            {glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
            {glm::vec3(0.5f, 0.5f, -0.5f),   glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)},
            {glm::vec3(-0.5f, 0.5f, -0.5f),  glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, -1.0f)},

            {glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
            {glm::vec3(0.5f, -0.5f, 0.5f),   glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
            {glm::vec3(0.5f, 0.5f, 0.5f),    glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)},
            {glm::vec3(-0.5f, 0.5f, 0.5f),   glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f)},

            {glm::vec3(-0.5f, 0.5f, 0.5f),   glm::vec2(1.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
            {glm::vec3(-0.5f, 0.5f, -0.5f),  glm::vec2(1.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},
            {glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f)},

            {glm::vec3(0.5f, 0.5f, 0.5f),    glm::vec2(1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
            {glm::vec3(0.5f, 0.5f, -0.5f),   glm::vec2(1.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
            {glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec2(0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f)},
            {glm::vec3(0.5f, -0.5f, 0.5f),   glm::vec2(0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)},

            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
            {glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
            {glm::vec3(0.5f, -0.5f, 0.5f),   glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)},
            {glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f)},

            {glm::vec3(-0.5f, 0.5f, -0.5f),  glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
            {glm::vec3(0.5f, 0.5f, -0.5f),   glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
            {glm::vec3(0.5f, 0.5f, 0.5f),    glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
            {glm::vec3(-0.5f, 0.5f, 0.5f),   glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)}
    };

    std::vector<unsigned int> boxIndices{
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

    // Plane
    std::vector<rigel::Vertex> planeVertices{
            {glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec2(.0f, 1.0f),  glm::vec3(0.0f, 1.0f, 0.0f)},
            {glm::vec3(0.5f, 0.0f, -0.5f),  glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
            {glm::vec3(0.5f, 0.0f, 0.5f),   glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
            {glm::vec3(-0.5f, 0.0f, 0.5f),  glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)}
    };

    std::vector<unsigned int> planeIndices{
            0, 1, 2,
            2, 3, 0
    };

    rigel::Mesh box(boxVertices, boxIndices);
    rigel::Mesh plane(planeVertices, planeIndices);

    // Materials
    rigel::Material boxMaterial;
    rigel::Material planeMaterial;
    rigel::Material catMaterial;

    planeMaterial.setAmbient(glm::vec3(0.3f, 0.3f, 0.3f));
    planeMaterial.setDiffuse(glm::vec3(0.3f, 0.3f, 0.3f));
    planeMaterial.setSpecular(glm::vec3(0.3f, 0.3f, 0.3f));

    catMaterial.setDiffuse(glm::vec3(0.7f, 0.7f, 0.7f));
    catMaterial.setSpecular(glm::vec3(0.1f, 0.1f, 0.1f));
    catMaterial.setShininess(8.0f);

    // Lights
    rigel::PointLight pointLight1, pointLight2, pointLight3;

    pointLight1.setPosition(glm::vec3(0.0f, 6.0f, 0.0f));
    pointLight2.setPosition(glm::vec3(20.0f, 6.0f, 0.0f));
    pointLight3.setPosition(glm::vec3(-20.0f, 6.0f, 0.0f));

    // Shader
    rigel::StandardShader shader;
    shader.bind();

    rigel::Texture boxTexture("../res/textures/box.png");
    rigel::Texture planeTexture("../res/textures/pixel.png");
    rigel::Texture catTexture("../res/textures/cat.png");
    boxTexture.bind(0);
    planeTexture.bind(1);
    catTexture.bind(2);

    shader.setMaterial(boxMaterial);
    shader.setPointLights({pointLight1, pointLight2, pointLight3});

    shader.unbind();

    rigel::Renderer renderer;

    while (!glfwWindowShouldClose(window)) {
        auto currentFrame = (float) glfwGetTime();
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

        // Boxes
        shader.setTexture(0);
        shader.setMaterial(boxMaterial);
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(8.0f, 0.5f, 0.0f));
        model = glm::rotate(model, glm::radians(60.0f), glm::vec3(0, 1, 0));
        shader.setModelMatrix(model);
        renderer.drawMesh(box, shader);

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(9.0f, 0.5f, -2.0f));
        model = glm::rotate(model, glm::radians(10.0f), glm::vec3(0, 1, 0));
        shader.setModelMatrix(model);
        renderer.drawMesh(box, shader);

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(10.0f, 1.0f, 0.0f));
        model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
        shader.setModelMatrix(model);
        renderer.drawMesh(box, shader);

        // Plane
        shader.setTexture(1);
        shader.setMaterial(planeMaterial);
        model = glm::mat4(1.0f);
        model = glm::scale(model, glm::vec3(100.0f, 1.0f, 100.0f));
        shader.setModelMatrix(model);
        renderer.drawMesh(plane, shader);

        shader.unbind();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Renderer.h"
#include "StaticShader.h"
#include "Material.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "Texture.h"
#include "Camera.h"
#include "Spectator.h"
#include "Mesh.h"
#include "Model.h"

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
    spectator.setPosition(glm::vec3(0.0f, 0.5f, -1.0f));

    // Box
    std::vector<rigel::Vertex> boxVertices{
        { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f,  0.0f, -1.0f)},
        { glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f,  0.0f, -1.0f)},
        { glm::vec3(0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f,  0.0f, -1.0f)},
        { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f,  0.0f, -1.0f)},

        { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f,  0.0f,  1.0f)},
        { glm::vec3(0.5f, -0.5f,  0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f,  0.0f,  1.0f)},
        { glm::vec3(0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f,  0.0f,  1.0f)},
        { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f,  0.0f,  1.0f)},

        { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(-1.0f,  0.0f,  0.0f)},
        { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(-1.0f,  0.0f,  0.0f)},
        { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(-1.0f,  0.0f,  0.0f)},
        { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f,  0.0f,  0.0f)},

        { glm::vec3(0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(1.0f,  0.0f,  0.0f)},
        { glm::vec3(0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(1.0f,  0.0f,  0.0f)},
        { glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(1.0f,  0.0f,  0.0f)},
        { glm::vec3(0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(1.0f,  0.0f,  0.0f)},

        { glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, -1.0f,  0.0f)},
        { glm::vec3(0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, -1.0f,  0.0f)},
        { glm::vec3(0.5f, -0.5f,  0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, -1.0f,  0.0f)},
        { glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, -1.0f,  0.0f)},

        { glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f,  1.0f,  0.0f)},
        { glm::vec3(0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f,  1.0f,  0.0f)},
        { glm::vec3(0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f,  1.0f,  0.0f)},
        { glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f,  1.0f,  0.0f)}
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
    std::vector<rigel::Vertex> planeVertices { 
        { glm::vec3(-0.5f,  0.0f, -0.5f), glm::vec2(.0f, 1.0f), glm::vec3(0.0f,  1.0f,  0.0f) },
        { glm::vec3(0.5f,  0.0f, -0.5f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f,  1.0f,  0.0f) },
        { glm::vec3(0.5f,  0.0f,  0.5f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f,  1.0f,  0.0f) },
        { glm::vec3(-0.5f,  0.0f,  0.5f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f,  1.0f,  0.0f) }
    };

    std::vector<unsigned int> planeIndices{ 
        0, 1, 2, 
        2, 3, 0 
    };

    rigel::Model teapot("res/models/teapot.obj");

    rigel::Mesh box(boxVertices, boxIndices);
    rigel::Mesh plane(planeVertices, planeIndices);

    // Materials
    rigel::Material boxMaterial;
    rigel::Material planeMaterial;
    rigel::Material teapotMaterial;

    planeMaterial.setAmbient(glm::vec3(0.3f, 0.3f, 0.3f));
    planeMaterial.setDiffuse(glm::vec3(0.3f, 0.3f, 0.3f));
    planeMaterial.setSpecular(glm::vec3(0.3f, 0.3f, 0.3f));

    teapotMaterial.setAmbient(glm::vec3(1.0f, 0.54f, 0.1f));
    teapotMaterial.setDiffuse(glm::vec3(1.0f, 0.54f, 0.1f) / 2.0f);
    teapotMaterial.setSpecular(glm::vec3(1.0f, 0.54f, 0.1f));
    teapotMaterial.setShininess(64.0f);

    // Lights
    rigel::DirectionalLight directionalLight;
    rigel::PointLight pointLight1, pointLight2, pointLight3;
    rigel::SpotLight spotLight;

    pointLight1.setPosition(glm::vec3(-20.0f, 2.0f, 0.0f));
    pointLight2.setPosition(glm::vec3(0.0f, 2.0f, 0.0f));
    pointLight3.setPosition(glm::vec3(20.0f, 2.0f, 0.0f));

    spotLight.setPosition(glm::vec3(4.0f, 2.0f, 0.0f));
    spotLight.setDirection(glm::vec3(1.2f, -1.0f, 2.0f));

    // Shader
    rigel::StaticShader shader;
    shader.bind();

    rigel::Texture boxTexture("res/textures/box.png");
    rigel::Texture planeTexture("res/textures/pixel.png");
    boxTexture.bind(0);
    planeTexture.bind(1);

    shader.setMaterial(boxMaterial);
    shader.setDirectionalLights({ directionalLight });
    shader.setPointLights({ pointLight1, pointLight2, pointLight3 });
    shader.setSpotLights({ spotLight });

    shader.unbind();

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

        shader.setTexture(0);
        shader.setMaterial(boxMaterial);

        // Boxes
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(6.8f, 0.5f, 3.0f));
        model = glm::rotate(model, 60.0f, glm::vec3(0, 1, 0));
        shader.setModelMatrix(model);
        renderer.drawMesh(box, shader);

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(5.0f, 0.5f, 4.0f));
        model = glm::rotate(model, 20.0f, glm::vec3(0, 1, 0));
        shader.setModelMatrix(model);
        renderer.drawMesh(box, shader);

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(7.0f, 1.0f, 5.0f));
        model = glm::scale(model, glm::vec3(2.0f, 2.0f, 2.0f));
        shader.setModelMatrix(model);
        renderer.drawMesh(box, shader);

        shader.setTexture(1);
        shader.setMaterial(planeMaterial);

        // Plane
        model = glm::mat4(1.0f);
        model = glm::scale(model, glm::vec3(100.0f, 1.0f, 100.0f));
        shader.setModelMatrix(model);
        renderer.drawMesh(plane, shader);

        shader.setMaterial(teapotMaterial);

        // Teapot
        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 0.0f, 10.0f));
        model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
        model = glm::translate(model, glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, 45.0f, glm::vec3(0, 1, 0));
        shader.setModelMatrix(model);
        renderer.drawMesh(*teapot.getMeshes()[0], shader);

        shader.unbind();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
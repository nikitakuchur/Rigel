#ifndef RIGEL_H
#define RIGEL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// glutils
#include "glutils/IndexBuffer.h"
#include "glutils/VertexArray.h"
#include "glutils/VertexBuffer.h"
#include "glutils/Shader.h"

#include "Camera.h"
#include "Mesh.h"
#include "Renderer.h"
#include "Texture.h"
#include "Spectator.h"
#include "Window.h"

namespace rigel {
    void initialize() {
        glfwInit();
    }

    void terminate() {
        glfwTerminate();
    }
}

#endif //RIGEL_H

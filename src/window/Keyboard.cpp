#include "Keyboard.h"

namespace rigel {

    bool Keyboard::isKeyPressed(unsigned int key) {
        return glfwGetKey(glfwGetCurrentContext(), key) == GLFW_PRESS;
    }
}
#include "Input.h"

#include <iostream>

Input::Input(GLFWwindow* window)
{
    for (int i = 0; i < MAX_KEYS; i++) 
        keys[i] = false;

    for (int i = 0; i < MAX_BUTTONS; i++)
        buttons[i] = false;

    glfwSetWindowUserPointer(window, this);
}

Input::~Input()
{
}

bool Input::isKeyPressed(int key)
{
    if (key >= MAX_KEYS)
        return false;
    return keys[key];
}

bool Input::isButtonPressed(int button)
{
    if (button >= MAX_BUTTONS)
        return false;
    return buttons[button];
}

void Input::getMousePosition(double& x, double& y)
{
    x = this->x;
    y = this->y;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Input* input = (Input*)glfwGetWindowUserPointer(window);

    if (input->keys[key] = (action != GLFW_RELEASE)) 
        std::cout << key << " is pressed" << std::endl;
}

void buttonCallback(GLFWwindow* window, int button, int action, int mods)
{
    Input* input = (Input*)glfwGetWindowUserPointer(window);

    if (input->buttons[button] = (action != GLFW_RELEASE))
        std::cout << button << " is pressed" << std::endl;
}

void mousePositionCallback(GLFWwindow* window, double x, double y)
{
    Input* input = (Input*)glfwGetWindowUserPointer(window);

    input->x = x;
    input->y = y;

    std::cout << "x: " << input->x << ", y:" << input->y << std::endl;
}

#pragma once

#include <GLFW/glfw3.h>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

class Input
{
private:
    bool keys[MAX_KEYS];
    bool buttons[MAX_BUTTONS];
    double x, y;

public:
    Input(GLFWwindow* window);
    ~Input();

    bool isKeyPressed(int key);
    bool isButtonPressed(int button);
    void getMousePosition(double& x, double& y);

private:
    friend void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    friend void buttonCallback(GLFWwindow* window, int button, int action, int mods);
    friend void mousePositionCallback(GLFWwindow* window, double x, double y);
};
#include "Window.h"

namespace rigel {
    Window::Window(int width, int height, std::string title) {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        glfwMakeContextCurrent(m_window);
        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }

    bool Window::isOpen() {
        return !glfwWindowShouldClose(m_window);
    }

    void Window::makeContextCurrent() {
        glfwMakeContextCurrent(m_window);
    }

    void Window::swapBuffers() {
        glfwSwapBuffers(m_window);
    }

    int Window::getWidth() {
        int width;
        glfwGetWindowSize(m_window, &width, nullptr);
        return width;
    }

    int Window::getHeight() {
        int height;
        glfwGetWindowSize(m_window, nullptr, &height);
        return height;
    }
}

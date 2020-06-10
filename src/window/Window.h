#ifndef RIGEL_WINDOW_H
#define RIGEL_WINDOW_H

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace rigel {
    class Window {
    private:
        GLFWwindow *m_window;
    public:
        Window(int width, int height, std::string title);

        inline GLFWwindow *getGLFWwindow() {
            return m_window;
        }

        bool isOpen();

        void close();

        void makeContextCurrent();

        void swapBuffers();

        int getWidth();

        int getHeight();
    };
}

#endif //RIGEL_WINDOW_H

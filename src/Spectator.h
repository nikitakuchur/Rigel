#ifndef RIGEL_SPECTATOR_H
#define RIGEL_SPECTATOR_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include "Camera.h"
#include "Window.h"

namespace rigel {
    class Spectator {
    private:
        rigel::Camera m_camera;
        glm::vec3 m_position;
        float m_rotation;
        float m_speed;
        float m_sensitivity;

        // Mouse handling
        bool firstMouse;
    public:
        Spectator();

        ~Spectator();

        inline rigel::Camera getCamera() const { return m_camera; }

        void setPosition(const glm::vec3 &position);

        inline glm::vec3 getPosition() const { return m_position; }

        void update(rigel::Window window, float deltaTime);
    };
}

#endif //RIGEL_SPECTATOR_H

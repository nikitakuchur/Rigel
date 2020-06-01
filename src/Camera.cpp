#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace rigel {
    Camera::Camera(float viewportWidth, float viewportHeight)
            : m_position(0.0f, 0.0f, 0.0f), m_worldUp(0.0f, 1.0f, 0.0f),
              m_viewportWidth(viewportWidth), m_viewportHeight(viewportHeight),
              m_pitch(0), m_yaw(0) {
        update();
    }

    glm::mat4 Camera::getViewMatrix() {
        return glm::lookAt(m_position, m_position + m_front, m_up);
    }

    void Camera::update() {
        m_front = glm::vec3(0.0f, 0.0f, 1.0f);

        glm::mat4 matX = glm::mat4(1.0f);
        matX = glm::rotate(matX, glm::radians(m_pitch), glm::vec3(1.0f, 0.0f, 0.0f));

        glm::mat4 matY = glm::mat4(1.0f);
        matY = glm::rotate(matY, glm::radians(m_yaw), glm::vec3(0.0f, 1.0f, 0.0f));

        glm::mat4 mat = matY * matX;

        m_front = glm::mat3(mat) * m_front;

        m_right = glm::normalize(glm::cross(m_front, m_worldUp));
        m_up = glm::normalize(glm::cross(m_right, m_front));
    }
}
#include "PerspectiveCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace rigel {
    PerspectiveCamera::PerspectiveCamera(float fieldOfView, float viewportWidth, float viewportHeight)
            : Camera(viewportWidth, viewportHeight), m_fieldOfView(fieldOfView) {
    }
    glm::mat4 PerspectiveCamera::getProjectionMatrix() const {
        return glm::perspective(glm::radians(m_fieldOfView), m_viewportWidth / m_viewportHeight, 0.01f, 1000.0f);
    }
}
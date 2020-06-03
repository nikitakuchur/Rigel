#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace rigel {
    glm::mat4 OrthographicCamera::getProjectionMatrix() const {
        return glm::ortho(-m_viewportWidth / 2, m_viewportWidth / 2, -m_viewportHeight / 2, m_viewportHeight / 2, 0.0f, 100.0f);
    }

    OrthographicCamera::OrthographicCamera(float viewportWidth, float viewportHeight)
            : Camera(viewportWidth, viewportHeight) {
    }
}

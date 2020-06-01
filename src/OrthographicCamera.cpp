#include "OrthographicCamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace rigel {
    glm::mat4 OrthographicCamera::getProjectionMatrix() const {
        return glm::ortho(0.0f, m_viewportWidth, m_viewportHeight, 0.0f, 0.01f, 100.0f);
    }
}
#include "Transformable.h"

#include "glm/gtc/matrix_transform.hpp"
#include <glm/gtx/quaternion.hpp>

rigel::Transformable::Transformable()
        : m_origin(0.f),
          m_position(0.f),
          m_rotation(0.f, 0.f, 0.f, 0.f),
          m_scale(1.f) {

}

glm::mat4 rigel::Transformable::getModel() const {
    glm::mat4 model = glm::mat4(1.f);
    model = glm::translate(model, m_position);
    model = model * glm::toMat4(m_rotation);
    model = glm::scale(model, m_scale);
    model = glm::translate(model, -m_origin);
    return model;
}

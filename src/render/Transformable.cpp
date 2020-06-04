#include "Transformable.h"

#include "glm/gtc/matrix_transform.hpp"

rigel::Transformable::Transformable()
        : m_origin(0.0f),
          m_position(0.0f),
          m_scale(1.0f) {

}

glm::mat4 rigel::Transformable::getModel() const {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, m_scale);
    model = glm::translate(model, -m_origin);
    model = glm::translate(model, m_position);
    // TODO: Add rotation
    return model;
}

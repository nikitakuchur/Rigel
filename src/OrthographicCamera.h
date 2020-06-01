#ifndef RIGEL_ORTHOGRAPHICCAMERA_H
#define RIGEL_ORTHOGRAPHICCAMERA_H

#include <glm/glm.hpp>
#include "Camera.h"

namespace rigel {
    class OrthographicCamera : public Camera {
    public:
        glm::mat4 getProjectionMatrix() const override;
    };
}

#endif //RIGEL_ORTHOGRAPHICCAMERA_H

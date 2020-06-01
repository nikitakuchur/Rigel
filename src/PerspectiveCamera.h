#ifndef RIGEL_PERSPECTIVECAMERA_H
#define RIGEL_PERSPECTIVECAMERA_H

#include <glm/glm.hpp>
#include "Camera.h"

namespace rigel {
    class PerspectiveCamera : public Camera {
    private:
        float m_fieldOfView;
    public:
        PerspectiveCamera(float fieldOfView, float viewportWidth, float viewportHeight);

        glm::mat4 getProjectionMatrix() const override;
    };
}

#endif //RIGEL_PERSPECTIVECAMERA_H

#ifndef RIGEL_POINT_LIGHT_H
#define RIGEL_POINT_LIGHT_H

#include "Light.h"

namespace rigel {
    class PointLight : public Light {
    private:
        glm::vec3 m_position;
        float m_constant;
        float m_linear;
        float m_quadratic;

    public:
        PointLight()
                : Light(),
                  m_position(0.0f, 0.0f, 0.0f),
                  m_constant(1.0f),
                  m_linear(0.022f),
                  m_quadratic(0.0019f) {
        }

        inline void setPosition(const glm::vec3 &position) { m_position = position; }

        inline glm::vec3 getPosition() const { return m_position; }

        inline void setConstant(float constant) { m_constant = constant; }

        inline float getConstant() const { return m_constant; }

        inline void setLinear(float linear) { m_linear = linear; }

        inline float getLinear() const { return m_linear; }

        inline void setQuadratic(float quadratic) { m_quadratic = quadratic; }

        inline float getQuadratic() const { return m_quadratic; }
    };
}

#endif //RIGEL_POINT_LIGHT_H

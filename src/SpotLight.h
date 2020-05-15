#ifndef RIGEL_SPOT_LIGHT_H
#define RIGEL_SPOT_LIGHT_H

#include "PointLight.h"

namespace rigel {
    class SpotLight : public PointLight {
    private:
        glm::vec3 m_direction;
        float m_cutOff;
        float m_outerCutOff;

    public:
        SpotLight()
                : PointLight(),
                  m_direction(0.0f, -1.0f, 0.0f),
                  m_cutOff(glm::cos(glm::radians(16.5f))),
                  m_outerCutOff(glm::cos(glm::radians(20.0f))) {
        }

        inline void setDirection(const glm::vec3 &direction) { m_direction = direction; }

        inline glm::vec3 getDirection() const { return m_direction; }

        inline void setCutOff(float cutOff) { m_cutOff = cutOff; }

        inline float getCutOff() const { return m_cutOff; }

        inline void setOuterCutOff(float outerCutOff) { m_outerCutOff = outerCutOff; }

        inline float getOuterCutOff() const { return m_outerCutOff; }
    };
}

#endif //RIGEL_SPOT_LIGHT_H

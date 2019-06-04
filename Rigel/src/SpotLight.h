#pragma once

#include "PointLight.h"

namespace rigel
{
    class SpotLight : public PointLight
    {
    private:
        glm::vec3 direction;
        float cutOff;
        float outerCutOff;

    public:
        SpotLight()
            : PointLight()
        {
            direction = glm::vec3(0.0f, -1.0f, 0.0f);
            cutOff = glm::cos(glm::radians(16.5f));
            outerCutOff = glm::cos(glm::radians(20.0f));
        }

        inline void setDirection(const glm::vec3& direction) { this->direction = direction; }
        inline glm::vec3 getDirection() const { return direction; }

        inline void setCutOff(float cutOff) { this->cutOff = cutOff; }
        inline float getCutOff() const { return cutOff; }

        inline void setOuterCutOff(float outerCutOff) { this->outerCutOff = outerCutOff; }
        inline float getOuterCutOff() const { return outerCutOff; }
    };
}
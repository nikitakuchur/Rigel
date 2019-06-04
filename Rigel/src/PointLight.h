#pragma once

#include "Light.h"

namespace rigel
{
    class PointLight : public Light
    {
    private:
        glm::vec3 position;
        float constant;
        float linear;
        float quadratic;

    public:
        PointLight()
            :Light()
        {
            position = glm::vec3(0.0f, 0.0f, 0.0f);
            constant = 1.0f;
            linear = 0.022f;
            quadratic = 0.0019f;
        }

        inline void setPosition(const glm::vec3& position) { this->position = position; }
        inline glm::vec3 getPosition() const { return position; }

        inline void setConstant(float constant) { this->constant = constant; }
        inline float getConstant() const { return constant; }

        inline void setLinear(float linear) { this->linear = linear; }
        inline float getLinear() const { return linear; }

        inline void setQuadratic(float quadratic) { this->quadratic = quadratic; }
        inline float getQuadratic() const { return quadratic; }
    };
}
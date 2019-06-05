#pragma once

#include "Light.h"

namespace rigel 
{
    class DirectionalLight : public Light
    {
    private:
        glm::vec3 m_direction;
    public:
        DirectionalLight()
            : Light()
        {
            m_direction = glm::vec3(0.0f, -1.0f, 0.0f);
        }

        inline void setDirection(const glm::vec3& direction) { m_direction = direction; }
        inline glm::vec3 getDirection() const { return m_direction; }
    };
}
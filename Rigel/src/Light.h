#pragma once

#include "glm/glm.hpp"

namespace rigel
{
    class Light
    {
    private:
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;

    public:
        Light()
        {
            ambient = glm::vec3(0.1f, 0.1f, 0.1f);
            diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
            specular = glm::vec3(1.0f, 1.0f, 1.0f);
        }

        inline void setAmbient(const glm::vec3& ambient) { this->ambient = ambient; }
        inline glm::vec3 getAmbient() const { return ambient; }

        inline void setDiffuse(const glm::vec3& diffuse) { this->diffuse = diffuse; }
        inline glm::vec3 getDiffuse() const { return diffuse; }

        inline void setSpecular(const glm::vec3& specular) { this->specular = specular; }
        inline glm::vec3 getSpecular() const { return specular; }
    };
}
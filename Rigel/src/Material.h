#pragma once

#include "glm/glm.hpp"

namespace rigel
{
    class Material 
    {
    private:
        glm::vec3 ambient;
        glm::vec3 diffuse;
        glm::vec3 specular;
        float shininess;

    public:
        Material()
        {
            ambient = glm::vec3(1.0f, 1.0f, 1.0f);
            diffuse = glm::vec3(1.0f, 1.0f, 1.0f);
            specular = glm::vec3(1.0f, 1.0f, 1.0f);
            shininess = 32.0f;
        }

        inline void setAmbient(const glm::vec3& ambient) { this->ambient = ambient; }
        inline glm::vec3 getAmbient() const { return ambient; }

        inline void setDiffuse(const glm::vec3& diffuse) { this->diffuse = diffuse; }
        inline glm::vec3 getDiffuse() const { return diffuse; }

        inline void setSpecular(const glm::vec3& specular) { this->specular = specular; }
        inline glm::vec3 getSpecular() const { return specular; }

        inline void setShininess(float shininess) { this->shininess = shininess; }
        inline float getShininess() const { return shininess; }
    };
}
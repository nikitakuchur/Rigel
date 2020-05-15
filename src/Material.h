#ifndef RIGEL_MATERIAL_H
#define RIGEL_MATERIAL_H

#include "glm/glm.hpp"

namespace rigel {
    class Material {
    private:
        glm::vec3 m_ambient;
        glm::vec3 m_diffuse;
        glm::vec3 m_specular;
        float m_shininess;

    public:
        Material() :
                m_ambient(1.0f, 1.0f, 1.0f),
                m_diffuse(1.0f, 1.0f, 1.0f),
                m_specular(1.0f, 1.0f, 1.0f),
                m_shininess(32.0f) {
        }

        inline void setAmbient(const glm::vec3 &ambient) { m_ambient = ambient; }

        inline glm::vec3 getAmbient() const { return m_ambient; }

        inline void setDiffuse(const glm::vec3 &diffuse) { m_diffuse = diffuse; }

        inline glm::vec3 getDiffuse() const { return m_diffuse; }

        inline void setSpecular(const glm::vec3 &specular) { m_specular = specular; }

        inline glm::vec3 getSpecular() const { return m_specular; }

        inline void setShininess(float shininess) { m_shininess = shininess; }

        inline float getShininess() const { return m_shininess; }
    };
}

#endif //RIGEL_MATERIAL_H

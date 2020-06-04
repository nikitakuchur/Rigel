#ifndef RIGEL_TRANSFORMABLE_H
#define RIGEL_TRANSFORMABLE_H


#include <glm/glm.hpp>
#include <glm/detail/type_quat.hpp>

namespace rigel {
    class Transformable {
    private:
        glm::vec3 m_origin;
        glm::vec3 m_position;
        glm::quat m_rotation;
        glm::vec3 m_scale;
    public:
        Transformable();

        inline const glm::vec3& getOrigin() const {
            return m_origin;
        }

        inline void setOrigin(const glm::vec3& origin) {
            m_origin = origin;
        }

        inline const glm::vec3& getPosition() const {
            return m_position;
        }

        inline void setPosition(const glm::vec3& position) {
            m_position = position;
        }

        inline const glm::quat& getRotation() const {
            return m_rotation;
        }

        inline void setRotation(const glm::quat& rotation) {
            m_rotation = rotation;
        }

        inline const glm::vec3& getScale() const {
            return m_scale;
        }

        inline void setScale(const glm::vec3& scale) {
            m_scale = scale;
        }

        glm::mat4 getModel() const;
    };
}


#endif //RIGEL_TRANSFORMABLE_H

#ifndef RIGEL_SPRITE_H
#define RIGEL_SPRITE_H

#include <glm/glm.hpp>
#include <render/Rect.h>
#include "TextureRectangle.h"
#include "Renderer.h"

namespace rigel {
    class Sprite {
    private:
        glm::vec3 m_position;
        float m_width;
        float m_height;
        IntRect m_textureRect;
        const TextureRectangle *m_texture;
        struct {
            glm::vec3 position;
            glm::vec2 texCoord;
        } m_vertices[8];
        unsigned int m_indices[6] = {0, 1, 3, 1, 2, 3};
    public:
        Sprite(const TextureRectangle &texture);

        void draw(const Renderer &renderer, const Shader &shader);

        inline glm::vec3 getPosition() const {
            return m_position;
        }

        inline void setPosition(glm::vec3 position) {
            m_position = position;
        }

        inline float getWidth() const {
            return m_width;
        }

        void setWidth(float width);

        inline float getHeight() const {
            return m_height;
        }

        void setHeight(float height);

        void setTextureRect(const IntRect& rect);

    private:
        void updateVertices();
    };
}

#endif //RIGEL_SPRITE_H

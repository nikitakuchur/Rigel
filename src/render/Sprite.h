#ifndef RIGEL_SPRITE_H
#define RIGEL_SPRITE_H

#include <glm/glm.hpp>
#include <render/Rect.h>
#include "TextureRectangle.h"
#include "Renderer.h"
#include "Transformable.h"

namespace rigel {
    class Sprite : public Transformable {
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

#include "Sprite.h"

namespace rigel {
    Sprite::Sprite(const TextureRectangle &texture)
            : m_position(),
              m_width((float) texture.getWidth()),
              m_height((float) texture.getHeight()),
              m_textureRect(0, 0, texture.getWidth(), texture.getHeight()),
              m_vertices{glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(m_textureRect.getLeft(), m_textureRect.getBottom()),
                       glm::vec3(0.0f, m_height, 0.0f), glm::vec2(m_textureRect.getLeft(), m_textureRect.getHeight()),
                       glm::vec3(m_width, m_height, 0.0f), glm::vec2(m_textureRect.getWidth(), m_textureRect.getHeight()),
                       glm::vec3(m_width, 0.0f, 0.0f), glm::vec2(m_textureRect.getWidth(), m_textureRect.getBottom())},
              m_texture(&texture) {
    }

    void Sprite::draw(const Renderer &renderer) {
        Mesh mesh(m_vertices, 4 * sizeof(m_vertices[0]), m_indices, 6 * sizeof(unsigned int),
                VertexAttribute::POSITION | VertexAttribute::TEXTURE_COORDINATE);
        renderer.draw(mesh);
    }

    void Sprite::setWidth(float width) {
        m_width = width;
        updatePositions();
    }

    void Sprite::setHeight(float height) {
        m_height = height;
        updatePositions();
    }

    void Sprite::setTextureRect(const IntRect& rect) {
        m_textureRect = IntRect(rect.getLeft(), rect.getBottom(), rect.getWidth(), rect.getHeight());
        updateTexCoords();
    }

    void Sprite::updatePositions() {
        m_vertices[0].position = glm::vec3(0.0f, 0.0f, 0.0f);
        m_vertices[1].position = glm::vec3(0.0f, m_height, 0.0f);
        m_vertices[2].position = glm::vec3(m_width, m_height, 0.0f);
        m_vertices[3].position = glm::vec3(m_width, 0.0f, 0.0f);
    }

    void Sprite::updateTexCoords() {
        m_vertices[0].texCoord = glm::vec2(m_textureRect.getLeft(), m_textureRect.getBottom());
        m_vertices[1].texCoord = glm::vec2(m_textureRect.getLeft(), m_textureRect.getHeight());
        m_vertices[2].texCoord = glm::vec2(m_textureRect.getWidth(), m_textureRect.getHeight());
        m_vertices[3].texCoord = glm::vec2(m_textureRect.getWidth(), m_textureRect.getBottom());
    }
}

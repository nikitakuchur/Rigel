#ifndef RIGEL_VERTEX_BUFFER_LAYOUT_H
#define RIGEL_VERTEX_BUFFER_LAYOUT_H

#include <vector>
#include <glad/glad.h>

namespace rigel {
    struct VertexBufferElement {
        unsigned int type;
        unsigned int count;
        unsigned char normalized;

        static unsigned int getSizeOfType(unsigned int type) {
            switch (type) {
                case GL_FLOAT:
                    return sizeof(GLfloat);
                case GL_UNSIGNED_INT:
                    return sizeof(GLuint);
                case GL_UNSIGNED_BYTE:
                    return sizeof(GLbyte);
                default:
                    return 0;
            }
        }
    };

    class VertexBufferLayout {
    private:
        std::vector<VertexBufferElement> m_elements;
        unsigned int m_stride;
    public:
        VertexBufferLayout()
                : m_stride(0) {}

        void push(unsigned int type, unsigned int count, bool normalized) {
            m_elements.push_back({type, count, (unsigned char) (normalized ? GL_TRUE : GL_FALSE)});
            m_stride += count * VertexBufferElement::getSizeOfType(type);
        }

        inline const std::vector<VertexBufferElement> &getElements() const { return m_elements; }

        inline unsigned int getStride() const { return m_stride; }
    };
}

#endif //RIGEL_VERTEX_BUFFER_LAYOUT_H

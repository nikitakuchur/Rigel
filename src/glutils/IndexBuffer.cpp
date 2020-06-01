#include "IndexBuffer.h"

namespace rigel {
    IndexBuffer::IndexBuffer(const unsigned int *indices, unsigned int count)
            : m_count(count) {
        glGenBuffers(1, &m_bufferId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    }

    void IndexBuffer::bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId);
    }

    void IndexBuffer::unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void IndexBuffer::remove() const {
        glDeleteBuffers(1, &m_bufferId);
    }
}
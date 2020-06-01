#include "VertexArray.h"

namespace rigel {
    VertexArray::VertexArray() {
        glGenVertexArrays(1, &m_arrayId);
    }

    void VertexArray::addBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) const {
        bind();
        vb.bind();

        const auto &elements = layout.getElements();

        unsigned long long offset = 0;

        for (unsigned int i = 0; i < elements.size(); i++) {
            const auto &element = elements[i];
            glEnableVertexAttribArray(i);
            glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void*) offset);
            offset += element.count * VertexBufferElement::getSizeOfType(element.type);
        }
    }

    void VertexArray::bind() const {
        glBindVertexArray(m_arrayId);
    }

    void VertexArray::unbind() const {
        glBindVertexArray(0);
    }

    void VertexArray::remove() const {
        glDeleteVertexArrays(1, &m_arrayId);
    }
}
#ifndef RIGEL_VERTEX_ARRAY_H
#define RIGEL_VERTEX_ARRAY_H

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace rigel {
    class VertexArray {
    private:
        unsigned int m_arrayId;
    public:
        VertexArray();

        void addBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) const;

        void bind() const;

        void unbind() const;

        void remove() const;
    };
}

#endif //RIGEL_VERTEX_ARRAY_H

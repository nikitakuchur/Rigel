#ifndef RIGEL_VERTEXARRAY_H
#define RIGEL_VERTEXARRAY_H

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace rigel {
    class VertexArray {
    private:
        unsigned int m_arrayId;
    public:
        VertexArray();
        ~VertexArray();

        void addBuffer(const VertexBuffer &vb, const VertexBufferLayout &layout) const;

        void bind() const;
        void unbind() const;
    };
}

#endif //RIGEL_VERTEXARRAY_H

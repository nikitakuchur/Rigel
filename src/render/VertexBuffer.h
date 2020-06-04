#ifndef RIGEL_VERTEXBUFFER_H
#define RIGEL_VERTEXBUFFER_H

#include <glad/glad.h>

namespace rigel {
    class VertexBuffer {
    private:
        unsigned int m_bufferId;
    public:
        VertexBuffer(const void *data, unsigned int size);
        ~VertexBuffer();

        void bind() const;
        void unbind() const;
    };
}

#endif //RIGEL_VERTEXBUFFER_H

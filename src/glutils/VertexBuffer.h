#ifndef RIGEL_VERTEX_BUFFER_H
#define RIGEL_VERTEX_BUFFER_H

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

#endif //RIGEL_VERTEX_BUFFER_H

#ifndef RIGEL_VERTEX_BUFFER_H
#define RIGEL_VERTEX_BUFFER_H

#include <glad/glad.h>

namespace rigel {
    class VertexBuffer {
    private:
        unsigned int m_bufferId;
    public:
        VertexBuffer(const void *data, unsigned int size);

        void bind() const;
        void unbind() const;
        void remove() const;
    };
}

#endif //RIGEL_VERTEX_BUFFER_H

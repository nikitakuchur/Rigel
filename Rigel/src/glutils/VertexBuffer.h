#pragma once

#include <GL/glew.h>

namespace rigel
{
    class VertexBuffer
    {
    private:
        unsigned int m_bufferId;
    public:
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();

        void bind() const;
        void unbind() const;
    };
}
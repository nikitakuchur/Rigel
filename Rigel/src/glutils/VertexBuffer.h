#pragma once

#include <GL/glew.h>

class VertexBuffer
{
private:
    unsigned int m_rendererId;
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void bind() const;
    void unbind() const;
};
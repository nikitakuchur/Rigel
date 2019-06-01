#pragma once

#include <GL/glew.h>

class IndexBuffer
{
private:
    unsigned int m_bufferId;
    unsigned int m_count; // The number of the indices
public:
    IndexBuffer(const unsigned int* indices, unsigned int count);
    ~IndexBuffer();

    void bind() const;
    void unbind() const;

    inline unsigned int getCount() const { return m_count; }
};
#pragma once

#include "glutils/VertexArray.h"
#include "glutils/IndexBuffer.h"
#include "Shader.h"

class Renderer
{
public:
    void clear() const;
    void drawElements(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
    void drawArrays(const VertexArray& va, unsigned int count, const Shader& shader) const;
};
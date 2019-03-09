#pragma once

#include "glutils/VertexArray.h"
#include "glutils/IndexBuffer.h"
#include "Shader.h"

class Renderer
{
public:
    void clear() const;
    void draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};
#pragma once

#include <string>
#include <vector>

#include "glm/glm.hpp"

#include "glutils/VertexBuffer.h"
#include "glutils/IndexBuffer.h"
#include "glutils/VertexArray.h"
#include "glutils/Shader.h"

namespace rigel
{
    class Mesh
    {
    private:
        std::vector<float> vertices;
        std::vector<unsigned int> indices;

        VertexArray* va;
        VertexBuffer vb;
        IndexBuffer* ib;
        VertexBufferLayout layout;
    public:
        Mesh(std::vector<float> vertices, std::vector<unsigned int> indices);
        ~Mesh();

        inline VertexArray* getVertexArray() const { return va; }
        inline IndexBuffer* getIndexBuffer() const { return ib; }
    };
}
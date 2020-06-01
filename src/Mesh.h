#ifndef RIGEL_MESH_H
#define RIGEL_MESH_H

#include <string>
#include <vector>

#include "glm/glm.hpp"

#include "glutils/VertexBuffer.h"
#include "glutils/IndexBuffer.h"
#include "glutils/VertexArray.h"
#include "glutils/Shader.h"

namespace rigel {
    enum VertexAttribute : unsigned int { POSITION = 2, TEXTURE_COORDINATE = 4, NORMAL = 8};
    class Mesh {
    private:
        VertexArray m_va;
        VertexBuffer m_vb;
        IndexBuffer m_ib;
        VertexBufferLayout m_layout;
    public:
        Mesh(void *vertices, unsigned int verticesSize, unsigned int *indices, unsigned int indicesSize, unsigned int attributes);

        ~Mesh();

        inline VertexArray getVertexArray() const { return m_va; }

        inline IndexBuffer getIndexBuffer() const { return m_ib; }
    };
}

#endif //RIGEL_MESH_H

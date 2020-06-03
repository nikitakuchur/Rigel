#ifndef RIGEL_MESH_H
#define RIGEL_MESH_H

#include <string>
#include <vector>

#include "glm/glm.hpp"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"

namespace rigel {
    enum VertexAttribute : unsigned int { POSITION = 2, TEXTURE_COORDINATE = 4, NORMAL = 8};
    class Mesh {
    private:
        VertexArray m_va;
        IndexBuffer m_ib;
    public:
        Mesh(void *vertices, unsigned int verticesSize, unsigned int *indices, unsigned int indicesSize, unsigned int attributes);

        void bind() const;
        void unbind() const;

        inline unsigned int getIndicesCount() const {
            return m_ib.getCount();
        }
    };
}

#endif //RIGEL_MESH_H

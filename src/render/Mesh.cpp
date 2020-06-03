#include "Mesh.h"

namespace rigel {

    Mesh::Mesh(void *vertices, unsigned int verticesSize, unsigned int *indices, unsigned int indicesSize, unsigned int attributes)
            : m_ib(indices, indicesSize){

        VertexBuffer vb(vertices, verticesSize);
        VertexBufferLayout layout;

        vb.bind();
        m_va.bind();
        m_ib.bind();

        if (attributes & VertexAttribute::POSITION) {
            layout.push(GL_FLOAT, 3, false);
        }
        if (attributes & VertexAttribute::TEXTURE_COORDINATE) {
            layout.push(GL_FLOAT, 2, false);
        }
        if (attributes & VertexAttribute::NORMAL) {
            layout.push(GL_FLOAT, 3, false);
        }

        m_va.addBuffer(vb, layout);

        vb.unbind();
        m_va.unbind();
        m_ib.unbind();
    }

    void Mesh::bind() const {
        m_va.bind();
        m_ib.bind();
    }

    void Mesh::unbind() const {
        m_va.unbind();
        m_ib.unbind();
    }
}

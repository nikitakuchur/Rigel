#include "Mesh.h"

namespace rigel {

    Mesh::Mesh(void *vertices, unsigned int verticesSize, unsigned int *indices, unsigned int indicesSize, unsigned int attributes)
            : m_vb(vertices, verticesSize),
            m_ib(indices, indicesSize){
        m_va.bind();
        m_vb.bind();
        m_ib.bind();

        if (attributes & VertexAttribute::POSITION) {
            m_layout.push(GL_FLOAT, 3, false); // Position
        }
        if (attributes & VertexAttribute::TEXTURE_COORDINATE) {
            m_layout.push(GL_FLOAT, 2, false); // TexCoord
        }
        if (attributes & VertexAttribute::NORMAL) {
            m_layout.push(GL_FLOAT, 3, false); // Normal
        }

        m_va.addBuffer(m_vb, m_layout);

        m_va.unbind();
        m_vb.unbind();
        m_ib.unbind();
    }

    Mesh::~Mesh() {
        m_va.remove();
        m_vb.remove();
        m_ib.remove();
    }
}

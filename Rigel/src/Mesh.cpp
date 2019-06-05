#include "Mesh.h"

namespace rigel
{
    Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
        :m_vb(&vertices[0], vertices.size() * sizeof(Vertex))
    {
        m_vertices = vertices;
        m_indices = indices;

        m_va = new VertexArray();
        m_ib = new IndexBuffer(&indices[0], indices.size());

        m_va->bind();
        m_vb.bind();
        m_ib->bind();

        m_layout.push(GL_FLOAT, 3, false); // Position
        m_layout.push(GL_FLOAT, 2, false); // TexCoord
        m_layout.push(GL_FLOAT, 3, false); // Normal

        m_va->addBuffer(m_vb, m_layout);

        m_va->unbind();
        m_vb.unbind();
        m_ib->unbind();
    }
    Mesh::~Mesh()
    {
        delete(m_va);
        delete(m_ib);
    }
}
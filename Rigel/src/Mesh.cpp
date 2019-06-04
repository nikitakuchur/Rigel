#include "Mesh.h"

namespace rigel
{
    Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
        :vb(&vertices[0], vertices.size() * sizeof(Vertex))
    {
        this->vertices = vertices;
        this->indices = indices;

        va = new VertexArray();
        ib = new IndexBuffer(&indices[0], indices.size());

        va->bind();
        vb.bind();
        ib->bind();

        layout.push(GL_FLOAT, 3, false); // Position
        layout.push(GL_FLOAT, 2, false); // TexCoord
        layout.push(GL_FLOAT, 3, false); // Normal

        va->addBuffer(vb, layout);

        va->unbind();
        vb.unbind();
        ib->unbind();
    }
    Mesh::~Mesh()
    {
        delete(va);
        delete(ib);
    }
}
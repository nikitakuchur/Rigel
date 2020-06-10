#include "Triangle.h"

namespace rigel {

    Triangle::Triangle(glm::vec3 point1, glm::vec3 point2, glm::vec3 point3)
            : m_vertices{point1, point2, point3},
              m_mesh(m_vertices, 3 * sizeof(m_vertices[0]), m_indices, 3 * sizeof(unsigned int),
                     VertexAttribute::POSITION) {
    }

    void Triangle::draw(Renderer &renderer) {
        m_mesh.bind();
        renderer.draw(m_mesh);
    }
}

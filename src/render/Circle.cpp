#include "Circle.h"

#include <cmath>
#include <glm/ext/scalar_constants.hpp>

namespace rigel {

    Circle::Circle(float radius, int segments)
            : m_radius(radius), m_segments(segments) {

    }

    void Circle::draw(Renderer &renderer) {
        glm::vec3 vertices[m_segments + 2]; // TODO: Fix

        vertices[0] = glm::vec3(0.f);

        float delta = 2.f * glm::pi<float>() / (float) m_segments;
        for (int i = 0; i < m_segments + 1; i++) {
            float t = (float) i * delta;
            vertices[i + 1] = glm::vec3(m_radius * std::cos(t), m_radius * std::sin(t), 0.f);
        }

        VertexBuffer vb(vertices, sizeof(vertices));
        VertexBufferLayout bufferLayout;

        bufferLayout.push(GL_FLOAT, 3, false); // Only positions

        VertexArray va;
        va.addBuffer(vb, bufferLayout);

        va.bind();
        glDrawArrays(GL_TRIANGLE_FAN, 0, m_segments + 2);
    }
}

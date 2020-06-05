#include "Renderer.h"

namespace rigel {
    void Renderer::clear() const {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::clear(float r, float g, float b) const {
        glClearColor(r, g, b, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::drawElements(const VertexArray &va, const IndexBuffer &ib) const {
        va.bind();
        ib.bind();
        glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr);
    }

    void Renderer::drawArrays(const VertexArray &va, unsigned int count) const {
        va.bind();
        glDrawArrays(GL_TRIANGLES, 0, count);
    }

    void Renderer::draw(const Mesh &mesh) const {
        mesh.bind();
        glDrawElements(GL_TRIANGLES, mesh.getIndicesCount(), GL_UNSIGNED_INT, nullptr);
    }
}
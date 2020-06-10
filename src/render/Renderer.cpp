#include "Renderer.h"

namespace rigel {
    Renderer::Renderer(const Shader &shader) : m_shader(&shader) {
    }

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
        m_shader->bind();
        glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr);
    }

    void Renderer::drawArrays(const VertexArray &va, unsigned int count) const {
        va.bind();
        m_shader->bind();
        glDrawArrays(GL_TRIANGLES, 0, count);
    }

    void Renderer::draw(const Mesh &mesh) const {
        mesh.bind();
        m_shader->bind();
        glDrawElements(GL_TRIANGLES, mesh.getIndicesCount(), GL_UNSIGNED_INT, nullptr);
    }
}
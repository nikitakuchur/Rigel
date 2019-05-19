#include "Renderer.h"

void Renderer::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::clear(float r, float g, float b) const
{
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::drawElements(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
    va.bind();
    ib.bind();
    shader.bind();
    glDrawElements(GL_TRIANGLES, ib.getCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::drawArrays(const VertexArray& va, unsigned int count, const Shader& shader) const
{
    va.bind();
    shader.bind();
    glDrawArrays(GL_TRIANGLES, 0, count);
}
#ifndef RIGEL_RENDERER_H
#define RIGEL_RENDERER_H

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Mesh.h"

namespace rigel {
    class Renderer {
    public:
        void clear() const;

        void clear(float r, float g, float b) const;

        void drawElements(const VertexArray &va, const IndexBuffer &ib) const;

        void drawArrays(const VertexArray &va, unsigned int count) const;

        void draw(const Mesh &mesh) const;
    };
}

#endif //RIGEL_RENDERER_H
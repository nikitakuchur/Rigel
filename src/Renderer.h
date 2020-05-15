#ifndef RIGEL_RENDERER_H
#define RIGEL_RENDERER_H

#include "glutils/VertexArray.h"
#include "glutils/IndexBuffer.h"
#include "glutils/Shader.h"
#include "Mesh.h"

namespace rigel {
    class Renderer {
    public:
        void clear() const;

        void clear(float r, float g, float b) const;

        void drawElements(const VertexArray &va, const IndexBuffer &ib, const Shader &shader) const;

        void drawArrays(const VertexArray &va, unsigned int count, const Shader &shader) const;

        void drawMesh(const Mesh &mesh, const Shader &shader) const;
    };
}

#endif //RIGEL_RENDERER_H
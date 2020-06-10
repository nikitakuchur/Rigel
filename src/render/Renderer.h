#ifndef RIGEL_RENDERER_H
#define RIGEL_RENDERER_H

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Mesh.h"

namespace rigel {
    class Renderer {
        const Shader *m_shader;
    public:
        Renderer(const Shader &shader);

        void clear() const;

        void clear(float r, float g, float b) const;

        inline const Shader &getShader() const {
            return *m_shader;
        }

        inline void setShader(const Shader &shader) {
            m_shader = &shader;
        }

        void drawElements(const VertexArray &va, const IndexBuffer &ib) const;

        void drawArrays(const VertexArray &va, unsigned int count) const;

        void draw(const Mesh &mesh) const;
    };
}

#endif //RIGEL_RENDERER_H
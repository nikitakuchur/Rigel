#ifndef RIGEL_TRIANGLE_H
#define RIGEL_TRIANGLE_H

#include <glm/glm.hpp>
#include "Renderer.h"
#include "Transformable.h"

namespace rigel {
    class Triangle : public Transformable {
    private:
        glm::vec3 m_vertices[3];
        unsigned int m_indices[3] = {0, 1, 2};
        Mesh m_mesh;
    public:
        Triangle(glm::vec3 point1, glm::vec3 point2, glm::vec3 point3);

        void draw(Renderer &renderer);
    };
}


#endif //RIGEL_TRIANGLE_H

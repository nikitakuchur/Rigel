#include "Renderer.h"
#include "Transformable.h"

#ifndef RIGEL_CIRCLE_H
#define RIGEL_CIRCLE_H


namespace rigel {
    class Circle : public Transformable {
    private:
        float m_radius;
        int m_segments;
    public:
        Circle(float radius = 32, int segments = 64);

        void draw(Renderer& renderer);
    };
}


#endif //RIGEL_CIRCLE_H

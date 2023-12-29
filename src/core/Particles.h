//
// Created by York Wu on 2023/12/29.
//

#ifndef PROJECT_PARTICLES_H
#define PROJECT_PARTICLES_H

#include <core/renderObject.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <utils/shader.h>
#include <vector>

struct Particle {
    glm::vec3 position, velocity;
    glm::vec4 color;
    float life;

    Particle() : position(0.0), velocity(0.0), color(0.3, 0.3, 1.0, 1.0), life(1.0){};
};

class Particles : RenderObject {
private:
    std::vector<Particle> particles;

public:
    Particles(Camera *, glm::mat4 *);
    void render() override;
    ~Particles();
};


#endif //PROJECT_PARTICLES_H

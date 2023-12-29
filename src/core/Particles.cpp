//
// Created by York Wu on 2023/12/29.
//

#include "Particles.h"

Particles::Particles(Camera *c, glm::mat4 *p) : RenderObject(c, p){
    shader = new Shader("shaders/particle.vert", "shaders/particle.frag");

}

Particles::~Particles() {

}

void Particles::render() {

}

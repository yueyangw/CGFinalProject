//
// Created by Joyce on 2023/12/30.
//

#include "CubeGroupYellow.h"
#include "LightingCubeYellow.h"

CubeGroupYellow::CubeGroupYellow(Camera *c, glm::mat4 *p) : RenderObject(c, p) {
    camera = c, projection = p;
    rotate = {
            glm::vec3(0.5f, 1.0f, 0.0f),
            glm::vec3(1.0f, 0.5f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.5f)
    };
    scaleData = {
            glm::vec3(0.5f, 0.5f, 0.5f),
            glm::vec3(0.3f, 0.3f, 0.3f),
            glm::vec3(0.1f, 0.1f, 0.1f)
    };
    for (int i = 0; i < 3; i++) {

        LightingCubeYellow *lightingCubeYellow = new LightingCubeYellow(camera, projection);
        lightingCubeYellow->setScale(scaleData[i]);
        lightingCubeYellow->setRotate(rotate[i]);
        cubes.push_back(lightingCubeYellow);
    }
}



void CubeGroupYellow::render() {
    for (int i = 0; i < scaleData.size(); i++) {
        cubes[i]->setScale(scaleData[i]);
        cubes[i]->setCurrentTime(getCurrentTime());
    }
    for (LightingCubeYellow *lightingCubeYellow: cubes) {
        lightingCubeYellow->setPosition(getPosition());
        lightingCubeYellow->render();
    }
}

void CubeGroupYellow::setScale(const glm::vec3 &scale) {
    for (auto &s : scaleData) {
        s = s * scale;
    }
    RenderObject::setScale(scale);
}

CubeGroupYellow::~CubeGroupYellow() noexcept {
    for (auto *cube : cubes) {
        delete cube;
    }
}
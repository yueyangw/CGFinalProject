//
// Created by Joyce on 2023/12/22.
//

#include <core/CubeGroup.h>

CubeGroup::CubeGroup(Camera *c, glm::mat4 *p) : RenderObject(c, p) {
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

        LightingCube *lightingCube = new LightingCube(camera, projection);
        lightingCube->setScale(scaleData[i]);
        lightingCube->setRotate(rotate[i]);
        cubes.push_back(lightingCube);
    }
}



void CubeGroup::render() {
    for (int i = 0; i < scaleData.size(); i++) {
        cubes[i]->setScale(scaleData[i]);
    }
    for (LightingCube *lightingCube: cubes) {
        lightingCube->setPosition(getPosition());
        lightingCube->render();
    }
}

void CubeGroup::setScale(const glm::vec3 &scale) {
    for (auto &s : scaleData) {
        s = s * scale;
    }
    RenderObject::setScale(scale);
}

CubeGroup::~CubeGroup() {
    for (auto *cube : cubes) {
        delete cube;
    }
}


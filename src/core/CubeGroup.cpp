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
            glm::vec3(1.0f, 1.0f, 1.0f),
            glm::vec3(0.5f, 0.5f, 0.5f),
            glm::vec3(0.1f, 0.1f, 0.1f)
    };
    for (int i = 0; i < 3; i++) {

        LightingCube *lightingCube = new LightingCube(camera, projection);
        lightingCube->setScale(scaleData[i]);
        lightingCube->setRotate(rotate[i]);
        printf("%lf",lightingCube->getScale()[0]);
        cubes.push_back(lightingCube);
    }
}



void CubeGroup::render() {

    for (LightingCube *lightingCube: cubes) {

        lightingCube->render();
    }
}


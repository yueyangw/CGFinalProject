//
// Created by York Wu on 2023/12/22.
//

#include <core/Ground.h>

Ground::Ground(Camera *c, glm::mat4 *p) : RenderObject(c, p) {
    camera = c, projection = p;
    blockPositions = {
            glm::vec3(0.0f, 0.0f, 2.0f),
            glm::vec3(-1.0f, 0.0f, 2.0f),
            glm::vec3(1.0f, 0.0f, 2.0f),

            glm::vec3(0.0f, 0.0f, 1.0f),
            glm::vec3(-1.0f, 0.0f, 1.0f),
            glm::vec3(1.0f, 0.0f, 1.0f),

            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(-1.0f, 0.0f, 0.0f),
            glm::vec3(1.0f, 0.0f, 0.0f),

            glm::vec3(0.0f, 0.0f, -1.0f),
            glm::vec3(-1.0f, 0.0f, -1.0f),
            glm::vec3(1.0f, 0.0f, -1.0f),

            glm::vec3(0.0f, 0.0f, -2.0f),
            glm::vec3(-1.0f, 0.0f, -2.0f),
            glm::vec3(1.0f, 0.0f, -2.0f),
    };
    for (glm::vec3 pos: blockPositions) {
        GroundBlock *block = new GroundBlock(camera, projection);
        block->setPosition(pos);
        block->setAnimateSpeed(0.4f);
        blocks.push_back(block);
    }
}

Ground::~Ground() {
    for (GroundBlock *block: blocks) {
        delete block;
    }
    blockPositions.clear();
    blocks.clear();
}

bool Ground::inBlock(GroundBlock *block) {
    float x = camera->Position.x, z = camera->Position.z;
    glm::vec3 pos = block->getPosition(), scale = block->getScale();
    float xmin = pos.x - scale.x / 2, xmax = pos.x + scale.x / 2;
    float zmin = pos.z - scale.z / 2, zmax = pos.z + scale.z / 2;
    if (x > xmin && x < xmax && z > zmin && z < zmax) {
        return true;
    }
    return false;
}

void Ground::render() {
    for (GroundBlock *block: blocks) {
        block->setInBlock(inBlock(block));
        block->setDeltaTime(getDeltaTime());
        block->render();
    }
}

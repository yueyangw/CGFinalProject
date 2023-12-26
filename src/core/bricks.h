//
// Created by Joyce on 2023/12/26.
//

#ifndef CGFINALPROJECT_BRICKS_H
#define CGFINALPROJECT_BRICKS_H


#include "glm/vec3.hpp"
#include "utils/camera.h"
#include "renderObject.h"

class Bricks : public RenderObject {

private:
    unsigned int diffuseMap, normalMap, heightMap;
    glm::mat4 view, projection;
public:
    Bricks(Camera*, glm::mat4 *p);
    void render() override;
};

#endif //CGFINALPROJECT_BRICKS_H

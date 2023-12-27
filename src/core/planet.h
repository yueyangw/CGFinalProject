//
// Created by Joyce on 2023/12/27.
//

#ifndef PROJECT_PLANET_H
#define PROJECT_PLANET_H

#include "renderObject.h"
#include "utils/model.h"

class Planet : public RenderObject {

private:
    unsigned int diffuseMap, normalMap, heightMap;
    glm::mat4 view, projection;
    Model *ourModel;

public:
    Planet(Camera*, glm::mat4 *p);
    void render() override;
};


#endif //CGFINALPROJECT_PLANET_H

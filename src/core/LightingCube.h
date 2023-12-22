//
// Created by Joyce on 2023/12/22.
//

#ifndef CGFINALPROJECT_LIGHTINGCUBE_H
#define CGFINALPROJECT_LIGHTINGCUBE_H

#include <core/renderObject.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <utils/shader.h>

class LightingCube : public RenderObject {
private:
    unsigned int texture1, texture2;

public:
    LightingCube(Camera*, glm::mat4 *p);
    void render() override;
};

#endif //CGFINALPROJECT_LIGHTINGCUBE_H

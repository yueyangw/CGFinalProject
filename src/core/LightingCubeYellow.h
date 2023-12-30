//
// Created by Joyce on 2023/12/30.
//

#ifndef CGFINALPROJECT_LIGHTINGCUBEYELLOW_H
#define CGFINALPROJECT_LIGHTINGCUBEYELLOW_H


#include <core/renderObject.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <utils/shader.h>

class LightingCubeYellow : public RenderObject {
private:
    glm::vec3 rotate;
public:
    void setRotate(const glm::vec3 &rotate);

private:
    unsigned int texture1;

public:
    LightingCubeYellow(Camera*, glm::mat4 *p);
    void render() override;
};


#endif //CGFINALPROJECT_LIGHTINGCUBEYELLOW_H

//
// Created by Joyce on 2023/12/22.
//

#ifndef CGFINALPROJECT_CUBEGROUP_H
#define CGFINALPROJECT_CUBEGROUP_H



#include <core/renderObject.h>
#include <core/LightingCube.h>
#include <vector>

class CubeGroup : public RenderObject {
private:
    std::vector<glm::vec3> scaleData;

private:
    std::vector<LightingCube*> cubes;
private:
    std::vector<glm::vec3> rotate;

public:
    CubeGroup(Camera*, glm::mat4*);
    void render() override;

    void setScale(const glm::vec3 &scale) override;

};


#endif //CGFINALPROJECT_CUBEGROUP_H

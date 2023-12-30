//
// Created by Joyce on 2023/12/30.
//

#ifndef CGFINALPROJECT_CUBEGROUPYELLOW_H
#define CGFINALPROJECT_CUBEGROUPYELLOW_H


#include <core/renderObject.h>
#include <core/LightingCubeYellow.h>
#include <vector>

class CubeGroupYellow : public RenderObject {
private:
    std::vector<glm::vec3> scaleData;

private:
    std::vector<LightingCubeYellow*> cubes;
private:
    std::vector<glm::vec3> rotate;

public:
    CubeGroupYellow(Camera*, glm::mat4*);
    ~CubeGroupYellow();
    void render() override;

    void setScale(const glm::vec3 &scale) override;

};

#endif //CGFINALPROJECT_CUBEGROUPYELLOW_H

//
// Created by York Wu on 2023/12/22.
//

#ifndef PROJECT_GROUND_H
#define PROJECT_GROUND_H

#include <core/renderObject.h>
#include <core/GroundBlock.h>
#include <vector>

class Ground : public RenderObject {
private:
    std::vector<glm::vec3> blockPositions;
    std::vector<GroundBlock*> blocks;
    bool inBlock(GroundBlock *block);

public:
    Ground(Camera*, glm::mat4*);
    void render() override;
    ~Ground();
};


#endif //PROJECT_GROUND_H

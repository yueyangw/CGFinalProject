//
// Created by Joyce on 2023/12/27.
//

#ifndef PROJECT_OBJFILEOBJECT_H
#define PROJECT_OBJFILEOBJECT_H

#include "renderObject.h"
#include "utils/model.h"

class ObjFileObject : public RenderObject {

private:
    glm::mat4 view, projection;
    Model *ourModel;

public:
    ObjFileObject(Camera*, glm::mat4 *p, const std::string &);
    ~ObjFileObject();
    void render() override;
};


#endif //CGFINALPROJECT_PLANET_H

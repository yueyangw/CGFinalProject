//
// Created by York Wu on 2023/12/18.
//

#ifndef PROJECT_RENDEROBJECT_H
#define PROJECT_RENDEROBJECT_H

class RenderObject {
private:
    int typeId;

public:
    unsigned int VAO, VBO;

    RenderObject();
    virtual void render() = 0;
    ~RenderObject();

};


#endif //PROJECT_RENDEROBJECT_H

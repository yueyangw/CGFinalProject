//
// Created by York Wu on 2023/12/18.
//

#ifndef PROJECT_RENDERPROCESS_H
#define PROJECT_RENDERPROCESS_H

#include <vector>
#include <core/renderObject.h>

using std::vector;

class RenderProcess {
private:
    double deltaTime;
    int windowWidth, windowHeight;
    vector<RenderObject*> objectList;

public:
    RenderProcess(int w, int h);
    ~RenderProcess();
    void doRenderStep(double deltaTime);
};


#endif //PROJECT_RENDERPROCESS_H

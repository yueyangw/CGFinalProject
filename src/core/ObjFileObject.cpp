//
// Created by Joyce on 2023/12/27.
//

#include <core/ObjFileObject.h>
#include "utils/model.h"


ObjFileObject::ObjFileObject(Camera* c, glm::mat4 *p, const std::string &path) : RenderObject(c, p) {
    shader = new Shader("shaders/1.model_loading.vert", "shaders/1.model_loading.frag");

    // load models
    // -----------
    ourModel = new Model(path.c_str());
    setScale(glm::vec3(0.3f, 0.3f, 0.3f));
}

ObjFileObject::~ObjFileObject() {
    delete ourModel;
}

void ObjFileObject::render() {

    shader->use();

    // view/projection transformations
    setVPMatrix();

    // render the loaded model
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, getPosition()); // translate it down so it's at the center of the scene
    model = glm::scale(model, getScale());	// it's a bit too big for our scene, so scale it down
    model = glm::rotate(model, (float) getCurrentTime()/10, glm::vec3(0.0f, 1.0f, 0.0f));
    shader->setMat4("model", model);
    ourModel->Draw(*shader);


}
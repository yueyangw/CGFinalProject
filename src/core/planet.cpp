//
// Created by Joyce on 2023/12/27.
//

#include <core/planet.h>
#include "utils/model.h"


Planet::Planet(Camera* c, glm::mat4 *p) : RenderObject(c, p) {
    shader = new Shader("shaders/1.model_loading.vert", "shaders/1.model_loading.frag");

    // load models
    // -----------
    ourModel = new Model("resources/obj/planet/planet.obj");
    setScale(glm::vec3(0.3f, 0.3f, 0.3f));
}

void Planet::render() {

    shader->use();

    // view/projection transformations
    glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)1000 / (float)750, 0.1f, 100.0f);
    glm::mat4 view = camera->GetViewMatrix();
    shader->setMat4("projection", projection);
    shader->setMat4("view", view);

    // render the loaded model
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, getPosition()); // translate it down so it's at the center of the scene
    model = glm::scale(model, getScale());	// it's a bit too big for our scene, so scale it down
    model = glm::rotate(model, (float) getCurrentTime()/10, glm::vec3(0.0f, 1.0f, 0.0f));
    shader->setMat4("model", model);
    ourModel->Draw(*shader);


}
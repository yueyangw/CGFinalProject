//
// Created by Joyce on 2023/12/27.
//

#include "planet.h"
#include "utils/model.h"
#include <stb_image.h>
#include <utils/filesystem.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Planet::Planet(Camera* c, glm::mat4 *p) : RenderObject(c, p) {
}

void Planet::render() {
    Shader ourShader("shaders/1.model_loading.vert", "shaders/1.model_loading.frag");

    // load models
    // -----------
    Model ourModel(FileSystem::getPath("resources/obj/planet/planet.obj"));
    ourShader.use();

    // view/projection transformations
    glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), (float)1000 / (float)750, 0.1f, 100.0f);
    glm::mat4 view = camera->GetViewMatrix();
    ourShader.setMat4("projection", projection);
    ourShader.setMat4("view", view);

    // render the loaded model
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
    model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));	// it's a bit too big for our scene, so scale it down
    model = glm::rotate(model, (float) glfwGetTime()/10, glm::vec3(0.0f, 1.0f, 0.0f));
    ourShader.setMat4("model", model);
    ourModel.Draw(ourShader);


}
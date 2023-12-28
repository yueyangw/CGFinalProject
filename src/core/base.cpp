//
// Created by Joyce on 2023/12/21.
//
#include <core/base.h>
#include <stb_image.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Base::Base(Camera* c, glm::mat4 *p) : RenderObject(c, p) {
    shader = new Shader("shaders/6.2.coordanite.vert", "shaders/6.2.coordanite.frag");
    float vertices[] = {
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
            0.5f, -0.4f, -0.5f, 1.0f, 1.0f,
            0.5f, -0.4f, -0.5f, 1.0f, 1.0f,
            -0.5f, -0.4f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, -0.4f, 0.5f, 1.0f, 1.0f,
            0.5f, -0.4f, 0.5f, 1.0f, 1.0f,
            -0.5f, -0.4f, 0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

            -0.5f, -0.4f, 0.5f, 1.0f, 0.0f,
            -0.5f, -0.4f, -0.5f, 1.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, -0.4f, 0.5f, 1.0f, 0.0f,

            0.5f, -0.4f, 0.5f, 1.0f, 0.0f,
            0.5f, -0.4f, -0.5f, 1.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            0.5f, -0.4f, 0.5f, 1.0f, 0.0f,

            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

            -0.5f, -0.4f, -0.5f, 0.0f, 1.0f,
            0.5f, -0.4f, -0.5f, 1.0f, 1.0f,
            0.5f, -0.4f, 0.5f, 1.0f, 0.0f,
            0.5f, -0.4f, 0.5f, 1.0f, 0.0f,
            -0.5f, -0.4f, 0.5f, 0.0f, 0.0f,
            -0.5f, -0.4f, -0.5f, 0.0f, 1.0f,

            //upbase
            -0.4f, -0.4f, -0.4f, 0.0f, 0.0f,
            0.4f, -0.4f, -0.4f, 1.0f, 0.0f,
            0.4f, -0.3f, -0.4f, 1.0f, 1.0f,
            0.4f, -0.3f, -0.4f, 1.0f, 1.0f,
            -0.4f, -0.3f, -0.4f, 0.0f, 1.0f,
            -0.4f, -0.4f, -0.4f, 0.0f, 0.0f,

            -0.4f, -0.4f, 0.4f, 0.0f, 0.0f,
            0.4f, -0.4f, 0.4f, 1.0f, 0.0f,
            0.4f, -0.3f, 0.4f, 1.0f, 1.0f,
            0.4f, -0.3f, 0.4f, 1.0f, 1.0f,
            -0.4f, -0.3f, 0.4f, 0.0f, 1.0f,
            -0.4f, -0.4f, 0.4f, 0.0f, 0.0f,

            -0.4f, -0.3f, 0.4f, 1.0f, 0.0f,
            -0.4f, -0.3f, -0.4f, 1.0f, 1.0f,
            -0.4f, -0.4f, -0.4f, 0.0f, 1.0f,
            -0.4f, -0.4f, -0.4f, 0.0f, 1.0f,
            -0.4f, -0.4f, 0.4f, 0.0f, 0.0f,
            -0.4f, -0.3f, 0.4f, 1.0f, 0.0f,

            0.4f, -0.3f, 0.4f, 1.0f, 0.0f,
            0.4f, -0.3f, -0.4f, 1.0f, 1.0f,
            0.4f, -0.4f, -0.4f, 0.0f, 1.0f,
            0.4f, -0.4f, -0.4f, 0.0f, 1.0f,
            0.4f, -0.4f, 0.4f, 0.0f, 0.0f,
            0.4f, -0.3f, 0.4f, 1.0f, 0.0f,

            -0.4f, -0.4f, -0.4f, 0.0f, 1.0f,
            0.4f, -0.4f, -0.4f, 1.0f, 1.0f,
            0.4f, -0.4f, 0.4f, 1.0f, 0.0f,
            0.4f, -0.4f, 0.4f, 1.0f, 0.0f,
            -0.4f, -0.4f, 0.4f, 0.0f, 0.0f,
            -0.4f, -0.4f, -0.4f, 0.0f, 1.0f,

            -0.4f, -0.3f, -0.4f, 0.0f, 1.0f,
            0.4f, -0.3f, -0.4f, 1.0f, 1.0f,
            0.4f, -0.3f, 0.4f, 1.0f, 0.0f,
            0.4f, -0.3f, 0.4f, 1.0f, 0.0f,
            -0.4f, -0.3f, 0.4f, 0.0f, 0.0f,
            -0.4f, -0.3f, -0.4f, 0.0f, 1.0f
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // texture 1
    // ---------
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    unsigned char *data = stbi_load("resources/textures/metal.png", &width, &height,
                                    &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    shader->use();
    shader->setInt("texture1", 0);
}

void Base::render() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);

    shader->use();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, this->getPosition());
    model = glm::translate(model, glm::vec3(0.0f, 0.5f, 0.0f));
//    model = glm::rotate(model, (float) glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
    shader->setMat4("model", model);
    setVPMatrix();

    // render box
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 72);
}

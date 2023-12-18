//
// Created by York Wu on 2023/12/18.
//

#include <glad/glad.h>
#include <core/exampleTriangle.h>

#include <iostream>

Triangle::Triangle() {
    shader = new Shader("shaders/3.3.shader.vert", "shaders/3.3.shader.frag");
}

void Triangle::render() {
    float vertices[] = {
            // positions         // colors
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom left
            0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f   // top
    };

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    shader->use();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

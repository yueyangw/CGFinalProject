

#include <glad/glad.h>
#include <core/floor.h>


#include <iostream>

Floor::Floor() {
    shader = new Shader("shaders/3.3.shader.vert", "shaders/3.3.shader.frag");
    float vertices[] = {
            // positions         // colors
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom left
            -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,  // top right
            0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,   // top left
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f  // bottom right
    };

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindVertexArray(0);
}

void Floor::render() {
    float vertices[] = {
            // positions         // colors
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom left
            -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,  // top right
            0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,   // top left
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f  // bottom right
    };

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

    shader->use();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawArrays(GL_TRIANGLES, 2, 3);
    glBindVertexArray(0);
}

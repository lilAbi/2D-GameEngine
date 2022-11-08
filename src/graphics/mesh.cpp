
#include "mesh.h"

Mesh::~Mesh() {
    //TODO: delete mesh buffers from GPU

}

void Mesh::BuildBuffer() {
    //if vaoObject doesnt exist
    if(!generated){
        glGenVertexArrays(1, &vaoObject);
        glGenBuffers(1, &vboObject);
        generated = true;
    }

    //bind vao and vbo
    glBindVertexArray(vaoObject);
    glBindBuffer(GL_ARRAY_BUFFER, vboObject);

    //allocate block of memory on gpu
    glBufferData(GL_ARRAY_BUFFER, (long)(vertexData.size() * sizeof(Vertex)), vertexData.data(), GL_DYNAMIC_DRAW);

    //"ptr" to position values
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);

    //"ptr" to color values
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(1);

    //unbind VAO
    glBindVertexArray(0);
}

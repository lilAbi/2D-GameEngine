#include "renderer.h"

void Renderer::Init() {

    shader = Shader("/Users/abi/CLionProjects/RougeGame/resource/shaderFiles/shader.vert",
                    "/Users/abi/CLionProjects/RougeGame/resource/shaderFiles/shader.frag");



    float vertices[] = {
            // positions         // colors
            0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
            0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top
    };

    std::vector<Vertex> test { {Vertex{{0.5f, -0.5f, 0.0f,}, {1.0f, 0.0f, 0.0f}},
                                Vertex{{-0.5f, -0.5f, 0.0f,}, {0.0f, 1.0f, 0.0f}},
                                Vertex{{0.0f, 0.5f, 0.0f,}, {0.0f, 0.0f, 1.0f}}}};

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * test.size(), test.data(), GL_DYNAMIC_DRAW);

    std::cout << "SIZE OF RENDER THINGS: " << sizeof(Vertex) * test.size();

    //glGetBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),  (void*)offsetof(Vertex, color) );
    glEnableVertexAttribArray(1);


}

void Renderer::Draw(Scene& scene){

    for(const auto* mesh : scene.meshContainer){
        if(mesh->meshStatus == MeshStatus::MESHED){

            //activate shader
            shader.use();

            //bind vao
            glBindVertexArray(mesh->vaoObject);

            //draw
            glDrawArrays(GL_TRIANGLES, 0, static_cast<int>(mesh->vertexData.size()));
            std::cout << "Drawing Size: "<< mesh->vertexData.size() << std::endl;
        }
    }

}



#ifndef ROUGEGAME_MESH_H
#define ROUGEGAME_MESH_H

#include <vector>
#include "glm/glm.hpp"
#include "glad/glad.h"
#include "glfw/glfw3.h"
#include <iostream>

enum class MeshType{
    LEVEL,
    PLAYER,
    UNKNOWN
};

enum class MeshStatus{
    UNMESHED,
    MESHED,
    UNKNOWN
};

struct Vertex {
    Vertex(glm::vec3 pos, glm::vec3 col) : position{pos}, color{col}{}
    glm::vec3 position{};
    glm::vec3 color{};
};

class Mesh {
public:
    explicit Mesh(MeshType type) : meshType(type){std::cout << "Mesh Constructed Player" << std::endl;}
    ~Mesh();

    //build mesh buffers
    void BuildBuffer();

public:
    unsigned int vaoObject{};
    unsigned int vboObject{};
    MeshType meshType{MeshType::UNKNOWN};
    MeshStatus meshStatus{MeshStatus::UNMESHED};
    std::vector<Vertex> vertexData{};
    bool generated{false};
};


#endif //ROUGEGAME_MESH_H

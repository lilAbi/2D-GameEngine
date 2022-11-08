
#ifndef ROUGEGAME_PLAYER_H
#define ROUGEGAME_PLAYER_H

#include "graphics/mesh.h"
#include "graphics/camera.h"
#include <iostream>

class Player {
public:
    Player(){
        std::cout << "Player Constructed" << std::endl;
    };
    ~Player() = default;

    Mesh& GetMesh(){return mesh;}

private:
    gfx::Camera camera{};
    Mesh mesh{MeshType::PLAYER};
};


#endif //ROUGEGAME_PLAYER_H

#ifndef ROUGEGAME_LEVEL_H
#define ROUGEGAME_LEVEL_H

#include <vector>
#include "glm/glm.hpp"
#include "tile.h"
#include "graphics/mesh.h"
#include "graphics/meshGenerator.h"
#include <iostream>

//A Level object that contains tilemap and their layers and
class Level {
public:
    //generate empty level filled with grass
    Level(int x, int y) : xPosition{x}, yPosition{y}, tileMap(MAP_AREA, TILES::GRASS){
        std::cout << "Level Constructed" << std::endl;
    };
    //mesh Level
    bool MeshLevel();
    //get/set mesh status
    MeshStatus GetMeshStatus() const {return mesh.meshStatus;}
    void SetMeshStatus(MeshStatus status){ mesh.meshStatus = status;}
    //get mesh data
    Mesh& GetMesh(){return mesh;}
private:
    //Upper Right
    int xPosition{-5};
    int yPosition{-5};
    //level data
    std::vector<TILES> tileMap;
    //mesh
    Mesh mesh{MeshType::LEVEL};
};


#endif //ROUGEGAME_LEVEL_H


#ifndef ROUGEGAME_SCENE_H
#define ROUGEGAME_SCENE_H
#include <vector>
#include "graphics/mesh.h"
#include <iostream>


//collection of render-able objects
class Scene {
public:
    Scene(){
        std::cout << "Scene Constructed" << std::endl;
    };
    ~Scene() = default;

    bool AddMeshToScene(const Mesh* mesh);
    bool RemoveMeshFromScene(const Mesh* mesh);

public:
    std::vector<const Mesh*> meshContainer;
};


#endif //ROUGEGAME_SCENE_H

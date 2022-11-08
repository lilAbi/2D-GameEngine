
#include "scene.h"

bool Scene::AddMeshToScene(const Mesh *mesh) {
    meshContainer.push_back(mesh);
    return true;
}

bool Scene::RemoveMeshFromScene(const Mesh *mesh) {

    if(std::remove(meshContainer.begin(), meshContainer.end(), mesh) != meshContainer.end()){
        return true;
    }

    return false;
}

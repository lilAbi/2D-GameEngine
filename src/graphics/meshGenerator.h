
#ifndef ROUGEGAME_MESHGENERATOR_H
#define ROUGEGAME_MESHGENERATOR_H

#include "graphics/mesh.h"
#include "game/level.h"



class MeshGenerator{
public:
    explicit MeshGenerator(Mesh& meshInstance);
    ~MeshGenerator(){};

    bool GenerateMeshFromTileMap(const std::vector<TILES>& tiles, int x, int y);

    void GenerateTestMesh();

private:
    void AddQuadToContainer(int length, int height, int x, int y);

private:
    Mesh& mesh;
};






#endif //ROUGEGAME_MESHGENERATOR_H

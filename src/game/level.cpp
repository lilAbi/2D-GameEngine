
#include "level.h"

bool Level::MeshLevel() {
    //TODO: function to generate mesh value

    //create a mesh generator object
    MeshGenerator meshGenerator(mesh);
    //generate a mesh from the tile
    meshGenerator.GenerateMeshFromTileMap(tileMap, xPosition, yPosition);

    return true;
}

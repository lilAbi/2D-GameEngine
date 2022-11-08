
#include "meshGenerator.h"
#include <string>

MeshGenerator::MeshGenerator(Mesh& meshInstance): mesh{meshInstance} {}

bool MeshGenerator::GenerateMeshFromTileMap(const std::vector<TILES>& tiles, int x, int y) {
    std::vector<TILES> mask(tiles);

    int quadPosX = x + 0;
    int quadPosY = y + MAP_Y;

    //find starting position
    for(int height{0}; height < MAP_Y; ++height){
        for(int width{0}; width < MAP_X; ++width){
            //get current tile
            auto currentTile = mask[width + (height*MAP_X)];

            if(currentTile == TILES::EMPTY || currentTile == TILES::UNKNOWN){
                continue;
            }

            //find the maxLength
            int quadWith {1};
            //while within the bounds of the array and next tile is the same
            while((width + quadWith < MAP_X) && (mask[width+quadWith + (height*MAP_X)] == currentTile)){
                ++quadWith;
            }

            //find the height of the mesh
            int quadHeight{1};
            while(quadHeight + height < MAP_Y){
                int currWidth{0};
                bool flag{false};
                while( (currWidth < quadWith) && (mask[(width+currWidth) + ((height+quadHeight)*MAP_X)] == currentTile) ){
                    ++currWidth;
                    flag = true;
                }
                if(!flag){ break; }
                ++quadHeight;
            }

            //build quad
            AddQuadToContainer(quadWith, quadHeight, quadPosX, quadPosY-height);


            //clear just made
            for(int b{0}; b < quadHeight; ++b){
                for(int a{0}; a < quadWith; ++a){
                    mask[(width+a) + ((height+b)*MAP_X)] = TILES::EMPTY;
                }
            }

        }
    }//end of meshing


    //set up mesh
    mesh.BuildBuffer();
    return true;
}


void MeshGenerator::GenerateTestMesh(){

    mesh.meshStatus = MeshStatus::MESHED;

    static std::vector<Vertex> test { {Vertex{{0.5f, -0.5f, 0.0f,}, {1.0f, 0.0f, 0.0f}},
                                Vertex{{-0.5f, -0.5f, 0.0f,}, {0.0f, 1.0f, 0.0f}},
                                Vertex{{0.0f, 0.5f, 0.0f,}, {0.0f, 0.0f, 1.0f}}}};

    mesh.vertexData = std::move(test);

    mesh.BuildBuffer();
}

void MeshGenerator::AddQuadToContainer(int length, int height, int x, int y) {
    //calculate quad coordinates
    glm::vec3 upperRight{x+length, y, 0};
    glm::vec3 upperLeft{x, y, 0};
    glm::vec3 lowerRight{x+length, y-height, 0};
    glm::vec3 lowerLeft{x, y-height, 0};

    //push quad into buffer
    mesh.vertexData.push_back({lowerLeft, {0.0f, 0.9f, 1.0f}});
    mesh.vertexData.push_back({upperLeft, {0.0f, 0.9f, 1.0f}});
    mesh.vertexData.push_back({lowerRight, {0.0f, 0.9f, 1.0f}});

    mesh.vertexData.push_back({upperLeft, {0.0f, 0.9f, 1.0f}});
    mesh.vertexData.push_back({upperRight, {0.0f, 0.9f, 1.0f}});
    mesh.vertexData.push_back({lowerRight, {0.0f, 0.9f, 1.0f}});
}


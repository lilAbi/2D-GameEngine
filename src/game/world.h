
#ifndef ROUGEGAME_WORLD_H
#define ROUGEGAME_WORLD_H

#include <vector>
#include "game/level.h"
#include <iostream>

namespace game{
    //game world
    class World {
    public:
        World(){
            std::cout << "World Constructed" << std::endl;
        };
        //simulate world
        void Tick();

        Mesh& GetMesh(){return level.GetMesh();}

    private:
        Level level{0, 0};
    };
}


#endif //ROUGEGAME_WORLD_H

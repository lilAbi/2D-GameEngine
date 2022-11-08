
#ifndef ROUGEGAME_TILE_H
#define ROUGEGAME_TILE_H

const int MAP_X = 25;
const int MAP_Y = 25;
const int MAP_AREA = MAP_X * MAP_Y;

enum class TILES{
    EMPTY = 0,
    //GROUND TILES------------
    GRASS,
    DIRT,
    STONE,
    SAND,
    //OBJECT TILES------------
    TREE,
    BUSH,
    
    //RESOURCE TILES----------
    COPPER,
    IRON,
    GOLD,

    UNKNOWN
};


#endif //ROUGEGAME_TILE_H

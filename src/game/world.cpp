
#include "world.h"

void game::World::Tick() {
    //check to see if we need to load a new level or not

    //move player

    //simulate game update events

    //update any level changes

    //if mesh status is unknown or unmeshed then mesh it
    if(auto status = level.GetMeshStatus(); status == MeshStatus::UNKNOWN || status == MeshStatus::UNMESHED){
        level.MeshLevel();
        level.SetMeshStatus(MeshStatus::MESHED);
    }

}

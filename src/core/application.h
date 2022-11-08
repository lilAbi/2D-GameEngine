
#ifndef ROUGEGAME_APPLICATION_H
#define ROUGEGAME_APPLICATION_H
#include <chrono>
#include "window.h"
#include "game/world.h"
#include "game/player.h"
#include "graphics/renderer.h"
#include "graphics/scene.h"
#include "graphics/meshGenerator.h"


namespace core {
    //game application
    class Application {
    public:
        //default constructor
        Application(){
            std::cout << "Application Constructed" << std::endl;
        };
        //initialize subsystem features
        bool Init();
        //run game loop
        void Run();
        //clean up the application
        void CleanUp();
    private:
        //draw image to screen
        void Render();
        //process input
        void ProcessInput();
    private:
        core::Window window{1280, 720};
        game::World world;
        Player player;
        Scene scene;
        Renderer renderer;

        Mesh dummyMesh{MeshType::UNKNOWN};
    };

}


#endif //ROUGEGAME_APPLICATION_H

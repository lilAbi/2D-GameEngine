#include <iostream>
#include <core/application.h>
#include <memory>

int main() {


    auto game = std::make_unique<core::Application>();

    if(game->Init()){
        game->Run();
    }

    game->CleanUp();

    return 0;
}

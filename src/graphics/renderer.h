
#ifndef ROUGEGAME_RENDERER_H
#define ROUGEGAME_RENDERER_H

#include <vector>
#include "game/level.h"
#include "graphics/scene.h"
#include "shader.h"

//render
class Renderer {
public:
    Renderer(){
        std::cout << "Renderer Constructed" << std::endl;
    };

    void Init();

    //draw render targets take a collection of levels and draw each one
    void Draw(Scene& scene);

    void Draw(Mesh& worldMesh, Mesh& dummyMesh);

private:
    unsigned int vao{}, vbo{};
    Shader shader;
};


#endif //ROUGEGAME_RENDERER_H

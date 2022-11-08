
#include "application.h"

bool core::Application::Init() {

    if(!window.Init()){
        return false;
    }

    //initialize shaders
    renderer.Init();

    scene.AddMeshToScene(&world.GetMesh());

    return true;
}

void core::Application::Run() {
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    while(!glfwWindowShouldClose(window())){
        //calculate delta time
        auto currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        //poll input
        ProcessInput();

        //tick world
        world.Tick();

        //draw world
        Render();

        //swap pixel buffer and poll window events
        glfwSwapBuffers(window());
        glfwPollEvents();
    }

}

void core::Application::CleanUp() {

}


void core::Application::Render() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //draw a scene
    renderer.Draw(scene);
}

void core::Application::ProcessInput() {

    if(glfwGetKey(window(), GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window(), true);
    }
}
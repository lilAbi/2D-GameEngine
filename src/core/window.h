#ifndef ROUGEGAME_WINDOW_H
#define ROUGEGAME_WINDOW_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

//window object
namespace core {

    class Window {
    public:
        //default constructor
        Window(int winWidth, int winHeight) : width(winWidth), height(winHeight){
            std::cout << "Window Constructed" << std::endl;
        }
        //initialize glfw and window
        bool Init();
        //return a ptr to glfw
        GLFWwindow* operator ()(){return glfwWindow;}
    private:
        int width{0};
        int height{0};
        GLFWwindow* glfwWindow{nullptr};
    };
}

#endif //ROUGEGAME_WINDOW_H

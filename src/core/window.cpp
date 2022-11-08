
#include "window.h"

bool core::Window::Init() {
    //initialize GLFW
    glfwInit();
    //configure glfw
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //create window
    glfwWindow = glfwCreateWindow(width, height, "Tower of God", nullptr, nullptr);

    if(!glfwWindow){
        std::cout << "failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    //set newly created window as current context
    glfwMakeContextCurrent(glfwWindow);

    //initialize glad
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "failed to initialize GLAD" << std::endl;
        return false;
    }

    return true;
}

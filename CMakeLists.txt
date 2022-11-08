cmake_minimum_required(VERSION 3.23)
project(RougeGame)
set(CMAKE_CXX_STANDARD 20)

link_directories("/usr/local/Cellar/llvm/15.0.0/lib/c++")
include_directories("/usr/local/Cellar/llvm/15.0.0/include/c++/v1")

include_directories(src)
include_directories(include)

find_package(glfw3 REQUIRED)
add_subdirectory(include/glm)

file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/*" "src/*/*" "src/*/*/*")

add_executable(RougeGame ${SRC_FILES})
target_link_libraries(RougeGame glfw)

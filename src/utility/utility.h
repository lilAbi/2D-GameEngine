
#ifndef ROUGEGAME_UTILITY_H
#define ROUGEGAME_UTILITY_H

#include <string>
#include <string_view>
#include <iostream>
#include <fstream>

namespace util{
    std::string ReadFromFile(std::string_view filePath);
}


#endif //ROUGEGAME_UTILITY_H

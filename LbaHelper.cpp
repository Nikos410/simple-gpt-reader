#include "LbaHelper.hpp"
#include <iostream>

LbaHelper::LbaHelper(std::string &devicePath, uint blockSize) {
    std::cout << "Opening " << devicePath << std::endl;
    deviceInputStream = std::ifstream(devicePath, std::ios::binary | std::ios::in);
    this->blockSize = blockSize;
}

LbaHelper::~LbaHelper() {
    std::cout << "Closing device." << std::endl;
    deviceInputStream.close();
}

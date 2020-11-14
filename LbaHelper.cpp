#include "LbaHelper.hpp"
#include <iostream>

LbaHelper::LbaHelper(std::string &devicePath, uint blockSize) {
    this->blockSize = blockSize;

    std::cout << "Opening " << devicePath << std::endl;
    deviceInputStream = std::ifstream(devicePath, std::ios::binary | std::ios::in);
    if (!deviceInputStream.is_open()) {
        std::cerr << "Could not open " << devicePath << std::endl;
        exit(EXIT_FAILURE);
    }
}

LbaHelper::~LbaHelper() {
    std::cout << "Closing device." << std::endl;
    deviceInputStream.close();
}

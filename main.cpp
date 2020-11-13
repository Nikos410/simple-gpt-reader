#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "GptHeader.hpp"

const uint BLOCK_SIZE = 512;

int main (int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "Please specify device" << std::endl;
        return EXIT_FAILURE;
    }
    char* device = argv[1];

    std::cout << "Opening " << device << std::endl;
    std::ifstream deviceInputStream = std::ifstream(device, std::ios::binary | std::ios::in);

    // We want to read the second block (after the gpt header)
    deviceInputStream.seekg(BLOCK_SIZE);

    std::vector<char> buffer = std::vector<char>(sizeof(GptHeader));
    if (deviceInputStream.read(buffer.data(), sizeof(GptHeader))) {
        deviceInputStream.close();
    } else {
        std::cerr << "Could not read data into buffer." << std::endl;
        return EXIT_FAILURE;
    }

    auto header = (GptHeader*)buffer.data();
    if (header->isValid()) {
        std::cout << "Found GPT Header:" << std::endl;
        std::cout << "###################" << std::endl;
        std::cout << header << std::endl;
    } else {
        std::cerr << "GPT Header not found. Is the disk partitioned using GPT?" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

#include <iostream>
#include <algorithm>
#include "GptHeader.hpp"
#include "LbaHelper.hpp"

std::string devicePathFromArgs(int argc, char* argv[]);
void printGptHeader(LbaHelper& lbaHelper);
GptHeader findGptHeader(LbaHelper& lbaHelper);

const uint BLOCK_SIZE = 512;

int main (int argc, char* argv[]) {
    std::string devicePath = devicePathFromArgs(argc, argv);
    auto lbaHelper = LbaHelper(devicePath, BLOCK_SIZE);

    printGptHeader(lbaHelper);

    return EXIT_SUCCESS;
}

std::string devicePathFromArgs(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "Please specify device" << std::endl;
        exit( EXIT_FAILURE);
    }

    return argv[1];
}

void printGptHeader(LbaHelper& lbaHelper) {
    auto header = findGptHeader(lbaHelper);
    if (header.isValid()) {
        std::cout << std::endl << "#### Found GPT Header ####" << std::endl;
        std::cout << header << std::endl << std::endl;
    } else {
        std::cerr << "GPT Header not found. Is the disk partitioned using GPT?" << std::endl;
        exit (EXIT_FAILURE);
    }
}

GptHeader findGptHeader(LbaHelper& lbaHelper) {
    return lbaHelper.read<GptHeader>(1);
}

#include <iostream>
#include <algorithm>
#include "GptHeader.hpp"
#include "LbaHelper.hpp"

std::string devicePathFromArgs(int argc, char* argv[]);
GptHeader findGptHeader(LbaHelper& lbaHelper);

const size_t BLOCK_SIZE = 512;

int main (int argc, char* argv[]) {
    std::string devicePath = devicePathFromArgs(argc, argv);
    auto lbaHelper = LbaHelper(devicePath, BLOCK_SIZE);

    auto GptHeader = findGptHeader(lbaHelper);
    // TODO: readFromLba partition entries

    return EXIT_SUCCESS;
}

std::string devicePathFromArgs(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "Please specify device" << std::endl;
        exit( EXIT_FAILURE);
    }

    return argv[1];
}

GptHeader findGptHeader(LbaHelper& lbaHelper) {
    auto header = lbaHelper.readFromLba<GptHeader>(1);
    if (header.isValid()) {
        std::cout << std::endl << "#### Found GPT Header ####" << std::endl;
        std::cout << header << std::endl << std::endl;
        return header;
    } else {
        std::cerr << "GPT Header not found. Is the disk partitioned using GPT?" << std::endl;
        exit (EXIT_FAILURE);
    }
}

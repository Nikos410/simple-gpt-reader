#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <algorithm>
#include "GptHeader.hpp"

const uint BLOCK_SIZE = 512;

int main (int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "Please specify device" << std::endl;
        return EXIT_FAILURE;
    }

    char* device = argv[1];
    int fd = open(device, O_RDONLY | O_NONBLOCK);
    if (fd < 0) {
        std::cerr << "Could not open block device " << device << std::endl;
        return EXIT_FAILURE;
    }

    // We want to read the second block (after the gpt header)
    lseek(fd, BLOCK_SIZE, SEEK_SET);

    char buffer[BLOCK_SIZE];
    int bytesRead = read(fd, buffer, BLOCK_SIZE);

    close(fd);

    std::cout << bytesRead << " bytes read." << std::endl;

    auto header = (GptHeader*)buffer;
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

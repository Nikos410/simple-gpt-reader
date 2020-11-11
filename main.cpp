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
    std::cout << std::endl << "### GPT Header ###" << std::endl;
    std::cout << "Signature: " << header->signature << std::endl;

    std::cout << "Revision: " ;
    for (char i : header->revision) {
        std::cout << (int)i << " ";
    }
    std::cout << std::endl;

    std::cout << "Header size: " << header->headerSize << std::endl;
    std::cout << "Current LBA: " << header->currentLba << std::endl;
    std::cout << "Backup LBA: " << header->backupLba << std::endl;
    std::cout << "firstUsableLba: " << header->firstUsableLba << std::endl;
    std::cout << "lastUsableLba: " << header->lastUsableLba << std::endl;

    std::cout << "diskGuid: " ;
    for (char i : header->diskGuid) {
        printf("%hhx",i);
    }
    std::cout << std::endl;

    std::cout << "First LBA of partition entry array: " << header->partitionEntryArrayLba << std::endl;
    std::cout << "Partition entry count: " << header->partitionEntryCount << std::endl;
    std::cout << "Partition entry size: " << header->partitionEntrySize << std::endl;

    return EXIT_SUCCESS;
}



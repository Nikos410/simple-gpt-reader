#include <iostream>
#include <algorithm>
#include "GptHeader.hpp"
#include "LbaHelper.hpp"
#include "GptPartitionEntry.hpp"

std::string devicePathFromArgs(int argc, char *argv[]);

GptHeader findGptHeader(LbaHelper &lbaHelper);

const size_t BLOCK_SIZE = 512;

int main(int argc, char *argv[]) {
    std::string devicePath = devicePathFromArgs(argc, argv);
    auto lbaHelper = LbaHelper(devicePath, BLOCK_SIZE);

    auto header = findGptHeader(lbaHelper);

    GptPartitionEntry partitionEntries[header.numberOfPartitionEntries];
    if (header.numberOfPartitionEntries == 0) {
        std::cout << "No partition entries." << std::endl;
        return EXIT_SUCCESS;
    }

    partitionEntries[0] = lbaHelper.readFromLba<GptPartitionEntry>(header.partitionEntryLba,
                                                                   header.sizeOfPartitionEntry);
    for (int i = 1; i < header.numberOfPartitionEntries; i++) {
        partitionEntries[i] = lbaHelper.readFromCurrentPosition<GptPartitionEntry>(header.sizeOfPartitionEntry);
    }

    for (int i = 0; i < header.numberOfPartitionEntries; i++) {
        GptPartitionEntry currentEntry = partitionEntries[i];
        if (currentEntry.isUsed()) {
            std::cout << "# Partition " << i << ":" << std::endl;
            std::cout << currentEntry << std::endl << std::endl;
        }

    }

    return EXIT_SUCCESS;
}

std::string devicePathFromArgs(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cerr << "Please specify device" << std::endl;
        exit(EXIT_FAILURE);
    }

    return argv[1];
}

GptHeader findGptHeader(LbaHelper &lbaHelper) {
    auto header = lbaHelper.readFromLba<GptHeader>(1);
    if (header.isValid()) {
        std::cout << std::endl << "#### Found GPT Header ####" << std::endl;
        std::cout << header << std::endl;
        std::cout << "#### End of GPT Header ####" << std::endl << std::endl;
        return header;
    } else {
        std::cerr << "GPT Header not found. Is the disk partitioned using GPT?" << std::endl;
        exit(EXIT_FAILURE);
    }
}

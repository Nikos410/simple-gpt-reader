#ifndef SIMPLE_GPT_READER_GPTPARTITIONENTRY_HPP
#define SIMPLE_GPT_READER_GPTPARTITIONENTRY_HPP

#include <cstdint>
#include "Uuid.hpp"

/**
 * Based on https://uefi.org/sites/default/files/resources/UEFI%20Spec%202.8B%20May%202020.pdf
 */
class GptPartitionEntry {
public:
    UUID partitionTypeGuid;
    UUID uniquePartitionGuid;
    uint64_t startingLba;
    uint64_t endingLba;
    uint64_t attributes;
    uint8_t partitionName[72];

    bool isUsed();
};

std::ostream& operator<<(std::ostream &os, GptPartitionEntry &entry);

#endif //SIMPLE_GPT_READER_GPTPARTITIONENTRY_HPP

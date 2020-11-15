#ifndef SIMPLE_GPT_READER_GPTPARTITIONENTRY_HPP
#define SIMPLE_GPT_READER_GPTPARTITIONENTRY_HPP

#include <cstdint>
#include "Uuid.hpp"

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

#endif //SIMPLE_GPT_READER_GPTPARTITIONENTRY_HPP

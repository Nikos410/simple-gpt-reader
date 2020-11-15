#ifndef SIMPLE_GPT_READER_GPTPARTITIONENTRY_HPP
#define SIMPLE_GPT_READER_GPTPARTITIONENTRY_HPP

#include <cstdint>

class GptPartitionEntry {
public:
    uint16_t partitionTypeGuid;
    uint16_t uniquePartitionGuid;
    uint8_t startingLba;
    uint8_t endingLba;
    uint8_t attributes;
    char partitionName[72];
};


#endif //SIMPLE_GPT_READER_GPTPARTITIONENTRY_HPP

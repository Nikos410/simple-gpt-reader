#ifndef SIMPLE_GPT_READER_GPT_HEADER_HPP
#define SIMPLE_GPT_READER_GPT_HEADER_HPP

#include <cstdint>
#include <sstream>
#include "Uuid.hpp"

/**
 * Based on https://uefi.org/sites/default/files/resources/UEFI%20Spec%202.8B%20May%202020.pdf
 */
class GptHeader {
public:
    // 8 bytes
    char signature[8];

    // 4 bytes
    char revision[4];

    // 4 bytes
    uint32_t headerSize;

    // 4 bytes
    char headerCrc32[4];

    // 4 bytes
    char reserved[4];

    // 8 bytes
    uint64_t myLba;

    // 8 bytes
    uint64_t alternateLba;

    // 8 bytes
    uint64_t firstUsableLba;

    // 8 bytes
    uint64_t lastUsableLba;

    // 16 bytes
    UUID diskGuid;

    // 8 bytes
    uint64_t partitionEntryLba;

    // 4 bytes
    uint32_t numberOfPartitionEntries;

    // 4 bytes
    uint32_t sizeOfPartitionEntry;

    // 4 bytes
    char partitionEntryArrayCrc32[4];

    bool isValid();
    friend std::ostream& operator<<(std::ostream &os, GptHeader &header);
};

#endif // SIMPLE_GPT_READER_GPT_HEADER_HPP

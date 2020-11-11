#ifndef SIMPLE_GPT_READER_GPT_HEADER_HPP
#define SIMPLE_GPT_READER_GPT_HEADER_HPP

#include <stdint.h>
#include <sstream>

class GptHeader {
public:
    bool isValid();
    friend std::ostream& operator<<(std::ostream &os, GptHeader *header);

private:

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
    uint64_t currentLba;

    // 8 bytes
    uint64_t backupLba;

    // 8 bytes
    uint64_t firstUsableLba;

    // 8 bytes
    uint64_t lastUsableLba;

    // 16 bytes
    char diskGuid[16];

    // 8 bytes
    uint64_t partitionEntryArrayLba;

    // 4 bytes
    uint32_t partitionEntryCount;

    // 4 bytes
    uint32_t partitionEntrySize;

    // 4 bytes
    char partitionEntryArrayCrc32[4];
};

#endif // SIMPLE_GPT_READER_GPT_HEADER_HPP

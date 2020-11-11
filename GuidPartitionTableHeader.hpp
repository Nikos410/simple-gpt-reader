#include <stdint.h>

class GuidPartitionTableHeader {
public:

    // 8 bytes
    char signature[8];

    // 4 bytes
    char revision[4];

    // 4 bytes
    uint32_t headerSize;

    // 4 bytes
    char crc32OfHeader[4];

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
    uint64_t startingLbaOfArrayOfPartitionEntries;

    // 4 bytes
    uint32_t numberOfPartitionEntries;

    // 4 bytes
    uint32_t sizeOfASinglePartitionEntry;

    // 4 bytes
    char crc32OfPartitionEntryArray[4];
};

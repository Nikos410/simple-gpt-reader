#include "GptPartitionEntry.hpp"

bool GptPartitionEntry::isUsed() {
    return UUID() != this->partitionTypeGuid;
}

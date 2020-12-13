#include "GptPartitionEntry.hpp"

bool GptPartitionEntry::isUsed() {
    return UUID() != this->partitionTypeGuid;
}

std::ostream &operator<<(std::ostream &os, GptPartitionEntry &entry) {
    os << "Unique partition GUID: " << entry.uniquePartitionGuid << std::endl;
    os << "Partition type GUID: " << entry.partitionTypeGuid << std::endl;

    os << "Starting LBA: " << entry.startingLba << std::endl;
    os << "Ending LBA: " << entry.endingLba;

    return os;
}

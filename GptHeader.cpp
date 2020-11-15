#include "GptHeader.hpp"

bool GptHeader::isValid() {
    return std::string(this->signature) == "EFI PART";
}

std::ostream &operator<<(std::ostream &os, GptHeader &header) {
    os << "Signature: " << header.signature << std::endl;

    os << "Revision: " ;
    for (char i : header.revision) {
        os << (int)i << " ";
    }
    os << std::endl;

    os << "Header size: " << header.headerSize << std::endl;
    os << "Current LBA: " << header.myLba << std::endl;
    os << "Backup LBA: " << header.alternateLba << std::endl;
    os << "firstUsableLba: " << header.firstUsableLba << std::endl;
    os << "lastUsableLba: " << header.lastUsableLba << std::endl;

    os << "diskGuid: " << header.diskGuid << std::endl;

    os << "First LBA of partition entry array: " << header.partitionEntryLba << std::endl;
    os << "Partition entry count: " << header.numberOfPartitionEntries << std::endl;
    os << "Partition entry size: " << header.sizeOfPartitionEntry;

    return os;
}

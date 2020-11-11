#include "Uuid.hpp"

std::ostream& operator<<(std::ostream &os, UUID &uuid) {
    os << uuid.format();
    return os;
}

std::string UUID::format() {
    std::stringstream resultStream;

    resultStream << std::hex;
    resultStream << this->timeLow;
    resultStream << "-";
    resultStream << this->timeMid;
    resultStream << "-";
    resultStream << this->timeHiAndVersion;
    resultStream << "-";
    resultStream << (int)this->clockSeqHighAndReserved;
    resultStream << (int)this->clockSeqLow;
    resultStream << "-";
    resultStream << this->formatNode();

    return resultStream.str();
}

std::string UUID::formatNode() {
    std::stringstream resultStream;

    resultStream << std::hex;
    for (unsigned char c : this->node) {
        resultStream << (int)c;
    }

    return resultStream.str();
}

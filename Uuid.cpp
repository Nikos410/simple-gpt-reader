#include "Uuid.hpp"
#include <iostream>
#include <array>

std::ostream &operator<<(std::ostream &os, UUID &uuid) {
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
    resultStream << (int) this->clockSeqHighAndReserved;
    resultStream << (int) this->clockSeqLow;
    resultStream << "-";
    resultStream << this->formatNode();

    return resultStream.str();
}

std::string UUID::formatNode() {
    std::stringstream resultStream;

    resultStream << std::hex;
    for (unsigned char c : this->node) {
        resultStream << (int) c;
    }

    return resultStream.str();
}

bool UUID::operator==(UUID &other) const {
    return this->timeLow == other.timeLow &&
           this->timeMid == other.timeMid &&
           this->timeHiAndVersion == other.timeHiAndVersion &&
           this->clockSeqHighAndReserved == other.clockSeqHighAndReserved &&
           this->clockSeqLow == other.clockSeqLow;
}

bool UUID::operator!=(UUID &other) const {
    return !(*this == other);
}

#ifndef SIMPLE_GPT_READER_UUID_HPP
#define SIMPLE_GPT_READER_UUID_HPP

#include <sstream>
#include <cstdint>

/**
 * Based on https://tools.ietf.org/html/rfc4122#section-4.1.2
 */
class UUID {
public:
    std::string format();
    bool operator==(UUID &other) const;
    bool operator!=(UUID &other) const;
private:
    std::string formatNode();

    uint32_t timeLow;
    uint16_t timeMid;
    uint16_t timeHiAndVersion;
    uint8_t clockSeqHighAndReserved;
    uint8_t clockSeqLow;
    uint8_t node[6];
};

std::ostream& operator<<(std::ostream &os, UUID &uuid);

#endif // SIMPLE_GPT_READER_UUID_HPP

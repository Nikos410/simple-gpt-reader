#ifndef SIMPLE_GPT_READER_LBAHELPER_HPP
#define SIMPLE_GPT_READER_LBAHELPER_HPP

#include <string>
#include <fstream>
#include <iostream>

class LbaHelper {
public:
    explicit LbaHelper(std::string& devicePath, uint blockSize);
    ~LbaHelper();

    template<typename T> T readFromLba(uint64_t firstLba) {
        return readFromLba<T>(firstLba, sizeof(T));
    }

    template<typename T> T readFromLba(uint64_t firstLba, size_t size) {
        deviceInputStream.seekg(firstLba * this->blockSize);
        return readFromCurrentPosition<T>(size);
    }

    template<typename T> T readFromCurrentPosition() {
        return readFromCurrentPosition<T>(sizeof(T));
    }

    template<typename T> T readFromCurrentPosition(size_t size) {
        char buffer[size];
        if (deviceInputStream.read(buffer, size)) {
            return *(T*) &buffer;
        } else {
            std::cerr << "Could not readFromLba data into buffer." << std::endl;
            exit(EXIT_FAILURE);
        }
    }
private:
    std::ifstream deviceInputStream;
    uint blockSize;
};


#endif //SIMPLE_GPT_READER_LBAHELPER_HPP

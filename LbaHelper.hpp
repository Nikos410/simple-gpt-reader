#ifndef SIMPLE_GPT_READER_LBAHELPER_HPP
#define SIMPLE_GPT_READER_LBAHELPER_HPP

#include <string>
#include <fstream>
#include <iostream>

class LbaHelper {
public:
    explicit LbaHelper(std::string& devicePath, uint blockSize);
    ~LbaHelper();

    template<typename T> T read(uint64_t firstLba) {
        deviceInputStream.seekg(firstLba * this->blockSize);

        size_t bufferSize = sizeof(T);

        char buffer[bufferSize];
        if (deviceInputStream.read(buffer, bufferSize)) {
            return *(T*) &buffer;
        } else {
            std::cerr << "Could not read data into buffer." << std::endl;
            exit(EXIT_FAILURE);
        }
    }
private:
    std::ifstream deviceInputStream;
    uint blockSize;
};


#endif //SIMPLE_GPT_READER_LBAHELPER_HPP

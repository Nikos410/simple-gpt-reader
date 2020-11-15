cmake_minimum_required(VERSION 3.16)
project(simple-gpt-reader)

set(CMAKE_CXX_STANDARD 20)

add_executable(simple-gpt-reader main.cpp GptHeader.hpp GptHeader.cpp  Uuid.hpp Uuid.cpp LbaHelper.hpp LbaHelper.cpp GptPartitionEntry.cpp GptPartitionEntry.hpp)
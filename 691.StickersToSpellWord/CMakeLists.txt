cmake_minimum_required(VERSION 3.8)
project(691_StickersToSpellWord)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cc)

add_executable(main ${SOURCE_FILES})
add_executable(691_StickersToSpellWord 691.stickers-to-spell-word.cpp)

cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++14")

set(SRC_LIST 
    scene
    destroyable
    entity
    creature
    map
    skill
)



add_library(logic ${SRC_LIST})

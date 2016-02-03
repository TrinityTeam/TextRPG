cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++14")

set(SRC_LIST 
    data_reader
    scene_reader
    entity_reader
    creature_reader
    command_parser
)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
find_package(JsonCpp REQUIRED)

add_library(io ${SRC_LIST})

target_include_directories(io PRIVATE ${JSONCPP_INCLUDE_DIR})
target_link_libraries(io ${JSONCPP_LIBRARIES})

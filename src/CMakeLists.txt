project(TextRPG)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++14")

set(SRC_LIST 
    main
    game
    scene
    scene_reader
)



set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
find_package(JsonCpp REQUIRED)

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_include_directories(${PROJECT_NAME} PRIVATE ${JSONCPP_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${JSONCPP_LIBRARIES})

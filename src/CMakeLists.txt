project(TextRPG)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++14")

set(SRC_LIST 
    main
    game
)



add_executable(${PROJECT_NAME} ${SRC_LIST})


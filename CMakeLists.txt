cmake_minimum_required(VERSION 3.28)
project(DADS)

set(CMAKE_CXX_STANDARD 17)
#add_subdirectory(2nd)
add_subdirectory(basicDataStructure)


add_executable(DADS
        main.cpp
)

target_link_libraries(DADS
    PUBLIC
#        CODE
        BASIC_DATA_STRUCTURE
)

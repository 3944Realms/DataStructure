cmake_minimum_required(VERSION 3.28)

add_library(CONST_LIB
        const.h
)
set_target_properties(CONST_LIB PROPERTIES LINKER_LANGUAGE CXX)
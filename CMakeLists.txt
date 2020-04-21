cmake_minimum_required(VERSION 3.15)
project(NRE_Data)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wno-virtual-move-assign -Wall -Wextra -Wfatal-errors -Wfloat-equal -Wstrict-overflow -Wshadow -Wconversion -Wunreachable-code -Wuninitialized -Winit-self -Werror -fstrict-overflow -O3 -std=c++17")

include_directories(C:/Users/abell/Documents/GitHub/NRE-Utility/src/)
include_directories(C:/Users/abell/Documents/GitHub/NRE-IO/src/)
include_directories(C:/Users/abell/Documents/GitHub/NRE-Memory/src/)
include_directories(.)
include_directories(src)

set(COMPILE_LIST
         )

set(EXEC_LIST
        ${COMPILE_LIST}
        src/NRE_Main.cpp)

add_executable(NRE_Data ${EXEC_LIST})

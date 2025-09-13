cmake_minimum_required(VERSION 3.10)

project(Lab_2)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/menu.cpp
    src/functions.cpp
    src/array.cpp
)

set(HEADERS
    include/menu.h
    include/functions.h
    include/array.h
    include/const.h
)

add_executable(Lab_2 ${SOURCES} ${HEADERS})
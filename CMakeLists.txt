cmake_minimum_required(VERSION 3.6)
project(DataBase)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Table.cpp Table.h TableRow.cpp TableRow.h DataBase.git/Engine.cpp DataBase.git/Engine.h DataBase.git/TableRepo.cpp DataBase.git/TableRepo.h)
add_executable(DataBase ${SOURCE_FILES})
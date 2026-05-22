cmake_minimum_required(VERSION 3.20)
project(genomescan-engine)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(genomescan-engine
    src/main.cpp
    src/server/HttpServer.cpp
    src/fasta/FastaParser.cpp
)
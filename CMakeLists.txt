cmake_minimum_required(VERSION 3.20)
project(keylogger VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE ALL_SOURCES 
    "src/*.cpp"
)

add_executable(mkit ${ALL_SOURCES})

set(CMAKE_GENERATOR, "mingw32-make")
cmake_minimum_required(VERSION 3.22.5)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
include(FetchContent)

project (cliipme)

file(GLOB SOURCES src/*.cpp)

add_executable(cliipme ${SOURCES})

target_include_directories(cliipme
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src/include
        ${DEVKITPRO}/wups/include
)

FetchContent_Declare(
    wups
)

FetchContent_MakeAvailable(wups)

target_link_libraries(cliipme wups)
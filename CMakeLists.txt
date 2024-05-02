cmake_minimum_required(VERSION 3.27)
project(DinoProject)

set(CMAKE_CXX_STANDARD 20)

set(BUILD_SHARED_LIBS FALSE)

include(FetchContent)

FETCHCONTENT_DECLARE(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.2.1
)
FETCHCONTENT_MAKEAVAILABLE(fmt)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY  https://github.com/SFML/SFML
        GIT_TAG         2.6.1
)

FetchContent_MakeAvailable(SFML)

add_executable(DinoProject main.cpp
        Dino.cpp
        Dino.h
        Objects.cpp
        Objects.h
        restartButton.cpp
        restartButton.h
        Window.cpp
        Window.h)
target_link_libraries(DinoProject fmt sfml-graphics)
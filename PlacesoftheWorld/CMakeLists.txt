cmake_minimum_required(VERSION 4.0)
project(COMP5004_places)

set(CMAKE_CXX_STANDARD 14)

# I'm telling CMake to build my executable from ALL THREE of my
# .cpp files. This is my main file, my Place class, and my PlaceManager class.
add_executable(COMP5004_places
        PlacesMain.cpp
        Place.cpp
        PlaceManager.cpp)
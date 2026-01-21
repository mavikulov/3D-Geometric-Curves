cmake_minimum_required(VERSION 3.16)

project(CAD
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cad_app
    main.cpp
    src/Point.cpp
    src/Curve3D.cpp
    src/Circle.cpp
    src/Ellipse.cpp
    src/Helix.cpp
)

target_include_directories(cad_app PRIVATE include)

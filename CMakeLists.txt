cmake_minimum_required(VERSION 3.27)
project(Lab06ComplexNumbers)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab06ComplexNumbers
        main.cpp
        Tests.h
        Tests.cpp
        Vector.h
        Vector.cpp
        Console.cpp
        Console.h
        Complex.cpp
        Complex.h
)

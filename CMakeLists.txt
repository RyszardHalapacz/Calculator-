cmake_minimum_required(VERSION 3.2)



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Calculator)

set(SRC_LIST 
    Structs.hpp
    Structs.cpp

    main.cpp
    String_Correction.cpp
    String_Correction.hpp
  
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
add_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra -g)
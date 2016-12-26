cmake_minimum_required(VERSION 3.6)
project(fillit)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

INCLUDE_DIRECTORIES(/home/Documents/GidHub/Univer/libft)
LINK_DIRECTORIES(/home/Documents/GidHub/Univer/libft)

add_library(libft.a STATIC IMPORTED)
#set_property(TARGET libft PROPERTY IMPORTED_LOCATION ../libft/libft.a)

set(SOURCE_FILES main.c fillit.h)
add_executable(fillit ${SOURCE_FILES} fillit.h)
#target_link_libraries(fillit /home/Documents/GidHub/Univer/libft/libft.a)
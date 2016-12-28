cmake_minimum_required(VERSION 3.6)
project(fillit)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

INCLUDE_DIRECTORIES(/home/cristian/Documents/Github/Univer/libft/)
LINK_DIRECTORIES(/home/cristian/Documents/Github/Univer/libft/)

add_library(libft.a STATIC IMPORTED_LOCATION
        /home/cristian/Documents/Github/Univer/libft/)
#set_property(TARGET libft PROPERTY IMPORTED_LOCATION ./home/cristian/Documents/Github/Univer/libft/libft.a)

set(SOURCE_FILES scr/main.c scr/fillit.h scr/solve.c scr/addition.c)
add_executable(fillit ${SOURCE_FILES} scr/fillit.h)
target_link_libraries(fillit /home/cristian/Documents/Github/Univer/libft/libft.a)
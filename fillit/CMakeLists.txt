cmake_minimum_required(VERSION 3.6)
project(fillit)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#INCLUDE_DIRECTORIES(/home/cristian/Documents/GidHub/Univer/libft/libft.h)
#LINK_DIRECTORIES(/home/cristian/Documents/GidHub/Univer/libft/)
#add_library(libft STATIC IMPORTED_LOCATION  /home/cristian/Documents/GidHub/Univer/libft/)
#set_property(TARGET libft PROPERTY IMPORTED_LOCATION ../libft/libft.a)

set(SOURCE_FILES main.c fillit.h solve.c)
add_executable(fillit ${SOURCE_FILES} fillit.h)
#target_link_libraries(fillit /home/cristian/Documents/GidHub/Univer/libft)
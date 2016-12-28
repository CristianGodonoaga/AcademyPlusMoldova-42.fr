cmake_minimum_required(VERSION 3.5.1)
project(fillit)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

INCLUDE_DIRECTORIES(/nfs/zfs-student-6/users/2016_cluj/cgodonoa/42/Univer/libft/)
LINK_DIRECTORIES(/nfs/zfs-student-6/users/2016_cluj/cgodonoa/42/Univer/libft/)

add_library(libft.a STATIC IMPORTED /nfs/zfs-student-6/users/2016_cluj/cgodonoa/42/Univer/libft/)
#set_property(TARGET libft PROPERTY IMPORTED_LOCATION ./home/cristian/Documents/Github/Univer/libft/libft.a)

set(SOURCE_FILES src/main.c src/fillit.h src/solve.c src/addition.c includes/libft/ft_lstfree.c)
add_executable(fillit ${SOURCE_FILES} src/fillit.h)
target_link_libraries(fillit /nfs/zfs-student-6/users/2016_cluj/cgodonoa/42/Univer/libft/libft.a)
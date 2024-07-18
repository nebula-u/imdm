cmake_minimum_required(VERSION 3.5.0)

project(imdm-server)

include_directories(./include)

aux_source_directory(./src DIR_SRCS)

link_directories(./lib)

add_executable(server ${DIR_SRCS})



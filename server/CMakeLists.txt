cmake_minimum_required(VERSION 3.5.0)

project(imdm-server)

include_directories(./include)
include_directories(./jsoncpp/json)

aux_source_directory(./src DIR_SRCS)
aux_source_directory(./jsoncpp DIR_SRCS_JSON)

link_directories(./lib)

add_executable(server ${DIR_SRCS} ${DIR_SRCS_JSON})



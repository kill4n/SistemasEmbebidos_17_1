cmake_minimum_required(VERSION 2.6)
project(pyRunner)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build_${CMAKE_SYSTEM_NAME})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

#add_subdirectory(dynamixel_aux)
#add_subdirectory(dynamixel_pro_aux)

#add_subdirectory(mensajes_aux)
add_subdirectory(extServUpdate)


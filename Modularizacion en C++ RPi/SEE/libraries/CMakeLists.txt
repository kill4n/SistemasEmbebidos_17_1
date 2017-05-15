cmake_minimum_required(VERSION 2.6)
project(SEELibs)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build_${CMAKE_SYSTEM_NAME})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

#add_subdirectory(dynamixel_aux)
#add_subdirectory(dynamixel_pro_aux)

add_subdirectory(semaphore_aux)
add_subdirectory(serial_aux)
add_subdirectory(socket_aux)
add_subdirectory(thread_aux)

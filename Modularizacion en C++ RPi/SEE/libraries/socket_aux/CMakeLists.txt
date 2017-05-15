cmake_minimum_required(VERSION 2.6)
project(socket_aux)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build_${CMAKE_SYSTEM_NAME})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

aux_source_directory(${PROJECT_SOURCE_DIR} ${PROJECT_NAME}_SRCS)
file(GLOB ${PROJECT_NAME}_HEADS "${PROJECT_INCLUDE_DIR}/*.h")

include_directories(${LIBS_DIR})

#add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRCS} ${${PROJECT_NAME}_HEADS})
ADD_LIBRARY(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SRCS} ${${PROJECT_NAME}_HEADS})
target_link_libraries(${PROJECT_NAME} thread_aux)
#MESSAGE( STATUS "SRC:" ${${PROJECT_NAME}_SRCS} )
#set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

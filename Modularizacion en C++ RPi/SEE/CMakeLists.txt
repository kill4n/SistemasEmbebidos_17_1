cmake_minimum_required(VERSION 2.6)
project(see_project)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build_${CMAKE_SYSTEM_NAME})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/Deploy)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(LIBS_DIR ${CMAKE_SOURCE_DIR}/libraries)
#set(MOTOR_DIR ${CMAKE_SOURCE_DIR}/motores)
#set(PRIF_DIR ${CMAKE_SOURCE_DIR}/perifericos)
#set(SENS_DIR ${CMAKE_SOURCE_DIR}/sensores)
#set(KINE_DIR ${CMAKE_SOURCE_DIR}/sensores)

#include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

#Agregar Carpetas
add_subdirectory(master)            #Programa maestro
#add_subdirectory(camControllers)    #camControllers
#add_subdirectory(gsmController)     #gsmController
add_subdirectory(libraries)         #libraries
#add_subdirectory(pyRunner)          #pyRunner
#add_subdirectory(ucSecurity)        #ucSecurity

#add_subdirectory(status)
#add_subdirectory(comunicacion)

#add_subdirectory(sensores)
#add_subdirectory(motores)
#add_subdirectory(perifericos)

#add_subdirectory(cinematica)



#add_subdirectory(test)

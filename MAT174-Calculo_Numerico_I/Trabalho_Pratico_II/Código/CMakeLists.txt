cmake_minimum_required(VERSION 2.8)

set( PROJECT_NAME "Numerico")

project(${PROJECT_NAME})

include_directories(include)

FILE(GLOB SRCS "*.cpp" "*.c")
FILE(GLOB INCLUDES "*.h" "*.hpp")

add_executable(${PROJECT_NAME} ${INCLUDES} ${SRCS} ${RESOURCES})
target_link_libraries(${PROJECT_NAME})

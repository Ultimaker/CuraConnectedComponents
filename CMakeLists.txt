project(CuraConnectedComponents)

cmake_minimum_required(VERSION 2.8.12)

find_package(PythonLibs 3.0 REQUIRED)

include(CMakeSip.cmake)

if(NOT ${CMAKE_VERSION} VERSION_LESS 3.1)
    set(CMAKE_CXX_STANDARD 11)
else()
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

# Add warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC")

include_directories(${CMAKE_CURRENT_BINARY_DIR} src ${PYTHON_INCLUDE_DIRS})

set(engine_SRCS
    src/main.cpp
    src/connectedComponentsComputation.cpp
    src/word.cpp
)

add_executable(CuraConnectedComponents ${engine_SRCS} ${engine_PB_SRCS})
target_link_libraries(CuraConnectedComponents)

if (UNIX)
    target_link_libraries(CuraConnectedComponents pthread)
endif()

install(TARGETS CuraConnectedComponents RUNTIME DESTINATION bin)

add_library(word STATIC src/word.cpp)
add_library(connectedComponentsComputation STATIC src/connectedComponentsComputation.cpp)

set(SIP_BINARY_PATH /usr/bin/sip)
ADD_SIP_PYTHON_MODULE(word src/word.sip word)
ADD_SIP_PYTHON_MODULE(connectedComponentsComputation src/connectedComponentsComputation.sip connectedComponentsComputation)

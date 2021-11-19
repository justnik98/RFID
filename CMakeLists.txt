cmake_minimum_required(VERSION 3.16)
project(rfid)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(rfid main.cpp rfid.cpp utils.cpp)
target_link_libraries(rfid PUBLIC ${CONAN_LIBS})
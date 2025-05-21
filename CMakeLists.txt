cmake_minimum_required(VERSION 3.30)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(bit_magic LANGUAGES CXX)

add_library(bit_magic)
add_library(bit_magic::bit_magic ALIAS bit_magic)

target_sources(bit_magic PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/src/bit_magic.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/print/print_binary_algorithms.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/print/print_binary_operators.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/print/print_util_functions.cpp
	${CMAKE_CURRENT_LIST_DIR}/src/util.cpp
)

target_include_directories(bit_magic 
  PUBLIC $<BUILD_LOCAL_INTERFACE: ${CMAKE_CURRENT_LIST_DIR}/include>
  PRIVATE $<BUILD_LOCAL_INTERFACE: ${CMAKE_CURRENT_LIST_DIR}/src>
)

set_target_properties(bit_magic PROPERTIES
  CXX_EXTENSIONS off
)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/app)

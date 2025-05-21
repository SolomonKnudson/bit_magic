cmake_minimum_required(VERSION 3.30)

add_executable(bit_test
  ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_link_libraries(bit_test  PRIVATE bit_magic::bit_magic)

set_target_properties(bit_test PROPERTIES
  CXX_EXTENSIONS off
)

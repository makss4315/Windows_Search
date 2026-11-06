cmake_minimum_required(VERSION 4.2)
project(findSystem)

set(CMAKE_CXX_STANDARD 23)

add_executable(findSystem
        main.cpp
        FileSearch.cpp
        FileSearch.h
       
)

enable_testing()

add_executable(missing_root_test
        tests/missing_root_test.cpp
        FileSearch.cpp
)

target_include_directories(missing_root_test
        PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}"
)

file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/test-work")

add_test(NAME missing_root_keeps_index COMMAND missing_root_test)

set_tests_properties(missing_root_keeps_index PROPERTIES
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/test-work"
)
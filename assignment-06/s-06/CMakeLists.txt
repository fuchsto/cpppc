cmake_minimum_required(VERSION 3.5.1)
project(midterm_assignment)

set(CMAKE_CXX_STANDARD 14)

include(cmake/enable_cxx_compiler_flag_if_supported.cmake)
enable_cxx_compiler_flag_if_supported("-Wall")
enable_cxx_compiler_flag_if_supported("-Wextra")
enable_cxx_compiler_flag_if_supported("-pedantic")
enable_cxx_compiler_flag_if_supported("-g")

include(.conan/conanbuildinfo.cmake)
conan_basic_setup()

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(SOURCE_FILES
        solution/array_expr.h
        solution/functional_expr.h
        solution/index_sequence.h
        solution/quicksort.h)
set(TEST_FILES
        test/TestBase.h test/testsuite.cc
        test/quicksort_test.cpp test/quicksort_test.h
        )

add_executable(testsuite ${TEST_FILES} ${SOURCE_FILES})
target_include_directories(testsuite PUBLIC .)
target_link_libraries(testsuite ${CONAN_LIBS} Threads::Threads)

cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(hello VERSION 1.0.0 LANGUAGES CXX)

find_package(PkgConfig)
pkg_check_modules(DRYLIB REQUIRED drylib-cpp)

add_executable(hello hello.cpp)
set_target_properties(hello PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
)
target_compile_options(hello PUBLIC ${DRYLIB_CFLAGS_OTHER})
target_include_directories(hello PUBLIC ${DRYLIB_INCLUDE_DIRS})
target_link_libraries(hello ${DRYLIB_LIBRARIES})

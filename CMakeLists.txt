cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

project(cs50 C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)

# Configure CPM
file(DOWNLOAD
     https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.40.2/CPM.cmake
     ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

# Configure compiler warnings
if("${CLANG_WARNINGS}" STREQUAL "")
  set(CLANG_WARNINGS
      -Wall
      -Wextra
      -Wshadow
      -Wnon-virtual-dtor
      -Wold-style-cast
      -Wcast-align
      -Wunused
      -Woverloaded-virtual
      -Wpedantic
      -Wconversion
      -Wsign-conversion
      -Wnull-dereference
      -Wdouble-promotion
      -Wformat=2
      -Wimplicit-fallthrough)
endif()

if("${GCC_WARNINGS}" STREQUAL "")
  set(GCC_WARNINGS
      ${CLANG_WARNINGS}
      -Wmisleading-indentation
      -Wduplicated-cond
      -Wduplicated-branches
      -Wlogical-op
      -Wuseless-cast
      -Wsuggest-override)
endif()

if(CMAKE_C_COMPILER_ID MATCHES ".*Clang")
  set(COMPILER_WARNINGS_CXX ${CLANG_WARNINGS})
elseif(CMAKE_C_COMPILER_ID STREQUAL "GNU")
  set(COMPILER_WARNINGS_CXX ${GCC_WARNINGS})
else()
  message(
    AUTHOR_WARNING
      "No compiler warnings set for C compiler: '${CMAKE_C_COMPILER_ID}'")
endif()

cpmaddpackage(
  NAME
  libcs50
  GIT_REPOSITORY
  https://github.com/cs50/libcs50
  VERSION
  11.0.3
  DOWNLOAD_ONLY
  YES)
if(libcs50_ADDED)
  execute_process(COMMAND make WORKING_DIRECTORY ${libcs50_SOURCE_DIR})
  find_library(LIB_CS50 cs50 PATHS ${libcs50_SOURCE_DIR}/build/lib/)
  find_path(LIB_CS50_HEADERS cs50.h PATHS ${libcs50_SOURCE_DIR}/build/include/)
  include_directories(${LIB_CS50_HEADERS})
endif()

file(GLOB SOURCE_FILES */*.c)
foreach(source_file ${SOURCE_FILES})
  get_filename_component(EXECUTABLE_NAME ${source_file} NAME_WE)
  add_executable(${EXECUTABLE_NAME} ${source_file})
  target_compile_options(${EXECUTABLE_NAME} PRIVATE ${COMPILER_WARNINGS_C})
  target_link_libraries(${EXECUTABLE_NAME} ${LIB_CS50})
  target_link_libraries(${EXECUTABLE_NAME} m)
endforeach()

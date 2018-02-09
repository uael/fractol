cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 OLD)
cmake_policy(SET CMP0045 OLD)

project(liblx C)
get_directory_property(liblx_PARENT PARENT_DIRECTORY)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

set(liblx_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(liblx_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(liblx_TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/test)

set(CMAKE_C_FLAGS "")
set(CMAKE_C_FLAGS_DEBUG "")
set(CMAKE_C_FLAGS_RELEASE "")

option(COVERAGE "Turn on COVERAGE support" OFF)
if (COVERAGE AND NOT MSVC)
  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} --coverage")
endif ()

if (NOT liblx_PARENT AND EXISTS ${liblx_TEST_DIR})
  enable_testing()
  add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})
  set(liblx_ENABLE_TEST ON)
else ()
  set(liblx_ENABLE_TEST OFF)
endif ()

set(liblx_HDR ${liblx_INC_DIR}/liblx.h)
file(GLOB_RECURSE liblx_HDRS ${liblx_HDRS}
  ${liblx_INC_DIR}/liblx/*.h)
file(GLOB_RECURSE liblx_SRCS ${liblx_SRCS}
  ${liblx_SRC_DIR}/*.c)
file(GLOB_RECURSE liblx_SRCS ${liblx_SRCS}
  ${liblx_SRC_DIR}/*.h)

add_library(lx ${liblx_HDR} ${liblx_HDRS} ${liblx_SRCS})
set_property(TARGET lx PROPERTY C_STANDARD 90)
target_include_directories(lx PUBLIC ${liblx_INC_DIR})
target_compile_definitions(lx PRIVATE U_COMPILE)
target_link_libraries(lx ft)

target_compile_definitions(lx
  PRIVATE $<$<CONFIG:Debug>:DEBUG>$<$<CONFIG:Release>:NDEBUG>
  PRIVATE API_COMPILE)
if (MSVC)
  target_compile_options(lx
    PRIVATE /MT$<$<CONFIG:Debug>:d> /Oy /W3
    PRIVATE /D_CRT_SECURE_NO_WARNINGS /Dinline=__inline
    PRIVATE /O$<$<CONFIG:Debug>:d>$<$<CONFIG:Release>:x>)
else ()
  target_compile_options(lx
    PRIVATE -Wall -Werror -Wextra
    PRIVATE -O$<$<CONFIG:Debug>:0 -g3>$<$<CONFIG:Release>:3>)
endif ()
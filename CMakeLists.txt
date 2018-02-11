cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
cmake_policy(SET CMP0054 OLD)
cmake_policy(SET CMP0045 OLD)

project(fractol C)
add_subdirectory(vendor/libft)

set(BUILD_SHARED_LIBS OFF)
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

set(fractol_INC_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(fractol_SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(fractol_TEST_DIR ${CMAKE_CURRENT_LIST_DIR}/test)

set(CMAKE_C_FLAGS "")
set(CMAKE_C_FLAGS_DEBUG "")
set(CMAKE_C_FLAGS_RELEASE "")

set(fractol_HDR ${fractol_INC_DIR}/fractol.h)
file(GLOB_RECURSE fractol_HDRS ${fractol_HDRS} ${fractol_INC_DIR}/fractol/*.h)
file(GLOB_RECURSE fractol_SRCS ${fractol_SRCS} ${fractol_SRC_DIR}/*.c)
file(GLOB_RECURSE fractol_SRCS ${fractol_SRCS} ${fractol_SRC_DIR}/*.h)

add_executable(fractol ${fractol_HDR} ${fractol_HDRS} ${fractol_SRCS})
set_property(TARGET fractol PROPERTY C_STANDARD 90)
target_include_directories(fractol PUBLIC ${fractol_INC_DIR})
target_link_libraries(fractol PUBLIC mlx pthread
  "-framework AppKit" "-framework OpenGL" debug ft)

target_compile_definitions(fractol
  PRIVATE $<$<CONFIG:Debug>:DEBUG>$<$<CONFIG:Release>:NDEBUG>)
if (MSVC)
  target_compile_options(fractol
    PRIVATE /MT$<$<CONFIG:Debug>:d> /Oy /W3
    PRIVATE /D_CRT_SECURE_NO_WARNINGS /Dinline=__inline
    PRIVATE /O$<$<CONFIG:Debug>:d>$<$<CONFIG:Release>:x>)
else ()
  target_compile_options(fractol
    PRIVATE -Wall -Werror -Wextra
    PRIVATE -O$<$<CONFIG:Debug>:0 -g3>$<$<CONFIG:Release>:3>)
endif ()

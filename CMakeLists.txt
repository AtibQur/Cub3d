cmake_minimum_required(VERSION 3.1)

project(cub3d)

#set(CMAKE_BUILD_PARALLEL_LEVEL "4")

### Google Test ###
configure_file(CMakeLists.txt.in
		googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
		 ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(tests)

### Source definitions ###

file(GLOB sources
	"${PROJECT_SOURCE_DIR}/inc/*.h"
	"${PROJECT_SOURCE_DIR}/src/parser/check_input.c"
	"${PROJECT_SOURCE_DIR}/src/main.c"
)

include(ExternalProject)
ExternalProject_Add(libft_lib
	SOURCE_DIR			"${PROJECT_SOURCE_DIR}/lib/libft"
	BINARY_DIR			"${PROJECT_SOURCE_DIR}/lib/libft"
	CONFIGURE_COMMAND	""
	BUILD_COMMAND		"make"
	INSTALL_COMMAND		""
	TEST_COMMAND		""
)

include_directories(
	"${PROJECT_SOURCE_DIR}/inc"
	"${PROJECT_SOURCE_DIR}/lib/libft"
)

link_directories(
	"${PROJECT_SOURCE_DIR}/lib/libft"
)

add_executable(cub3d ${sources})
target_compile_options(cub3d PRIVATE -Wextra -Wall -Werror -g)
target_link_libraries(cub3d libft.a)

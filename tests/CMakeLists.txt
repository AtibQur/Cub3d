include_directories(
	"${PROJECT_SOURCE_DIR}/inc"
	"${PROJECT_SOURCE_DIR}/lib/libft"
	"${PROJECT_SOURCE_DIR}/vendor/readline/include"
)

link_directories(
	"${PROJECT_SOURCE_DIR}/lib/libft"
)

### C Source Files ###
file(GLOB sources
			"${PROJECT_SOURCE_DIR}/src/check_input.c"
			"${PROJECT_SOURCE_DIR}/src/main.c"
		)
list(REMOVE_ITEM sources "${PROJECT_SOURCE_DIR}/src/main.c")

### CPP Test Files ###
file(GLOB tests
			"${PROJECT_SOURCE_DIR}/tests/*.cpp"
			)
list(REMOVE_ITEM tests "${PROJECT_SOURCE_DIR}/tests/main.cpp")

foreach(file ${tests})
	set(name)
	get_filename_component(name ${file} NAME_WE)
	add_executable("${name}_tests"
		${sources}
		${file}
		"${PROJECT_SOURCE_DIR}/tests/main.cpp")
	target_link_libraries("${name}_tests" gtest_main libft.a)
	target_compile_options("${name}_tests" PRIVATE -Wextra -Wall -g)
	add_test(NAME ${name} COMMAND "${name}_tests")
endforeach()

# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tvan-der/Desktop/Cub3d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tvan-der/Desktop/Cub3d/build

# Utility rule file for libft_lib.

# Include any custom commands dependencies for this target.
include CMakeFiles/libft_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/libft_lib.dir/progress.make

CMakeFiles/libft_lib: CMakeFiles/libft_lib-complete

CMakeFiles/libft_lib-complete: libft_lib-prefix/src/libft_lib-stamp/libft_lib-install
CMakeFiles/libft_lib-complete: libft_lib-prefix/src/libft_lib-stamp/libft_lib-mkdir
CMakeFiles/libft_lib-complete: libft_lib-prefix/src/libft_lib-stamp/libft_lib-download
CMakeFiles/libft_lib-complete: libft_lib-prefix/src/libft_lib-stamp/libft_lib-update
CMakeFiles/libft_lib-complete: libft_lib-prefix/src/libft_lib-stamp/libft_lib-patch
CMakeFiles/libft_lib-complete: libft_lib-prefix/src/libft_lib-stamp/libft_lib-configure
CMakeFiles/libft_lib-complete: libft_lib-prefix/src/libft_lib-stamp/libft_lib-build
CMakeFiles/libft_lib-complete: libft_lib-prefix/src/libft_lib-stamp/libft_lib-install
CMakeFiles/libft_lib-complete: libft_lib-prefix/src/libft_lib-stamp/libft_lib-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/tvan-der/Desktop/Cub3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'libft_lib'"
	/Applications/CMake.app/Contents/bin/cmake -E make_directory /Users/tvan-der/Desktop/Cub3d/build/CMakeFiles
	/Applications/CMake.app/Contents/bin/cmake -E touch /Users/tvan-der/Desktop/Cub3d/build/CMakeFiles/libft_lib-complete
	/Applications/CMake.app/Contents/bin/cmake -E touch /Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/src/libft_lib-stamp/libft_lib-done

libft_lib-prefix/src/libft_lib-stamp/libft_lib-build: libft_lib-prefix/src/libft_lib-stamp/libft_lib-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/tvan-der/Desktop/Cub3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing build step for 'libft_lib'"
	cd /Users/tvan-der/Desktop/Cub3d/lib/libft && make
	cd /Users/tvan-der/Desktop/Cub3d/lib/libft && /Applications/CMake.app/Contents/bin/cmake -E touch /Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/src/libft_lib-stamp/libft_lib-build

libft_lib-prefix/src/libft_lib-stamp/libft_lib-configure: libft_lib-prefix/tmp/libft_lib-cfgcmd.txt
libft_lib-prefix/src/libft_lib-stamp/libft_lib-configure: libft_lib-prefix/src/libft_lib-stamp/libft_lib-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/tvan-der/Desktop/Cub3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'libft_lib'"
	cd /Users/tvan-der/Desktop/Cub3d/lib/libft && /Applications/CMake.app/Contents/bin/cmake -E echo_append
	cd /Users/tvan-der/Desktop/Cub3d/lib/libft && /Applications/CMake.app/Contents/bin/cmake -E touch /Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/src/libft_lib-stamp/libft_lib-configure

libft_lib-prefix/src/libft_lib-stamp/libft_lib-download: libft_lib-prefix/src/libft_lib-stamp/libft_lib-source_dirinfo.txt
libft_lib-prefix/src/libft_lib-stamp/libft_lib-download: libft_lib-prefix/src/libft_lib-stamp/libft_lib-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/tvan-der/Desktop/Cub3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "No download step for 'libft_lib'"
	/Applications/CMake.app/Contents/bin/cmake -E echo_append
	/Applications/CMake.app/Contents/bin/cmake -E touch /Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/src/libft_lib-stamp/libft_lib-download

libft_lib-prefix/src/libft_lib-stamp/libft_lib-install: libft_lib-prefix/src/libft_lib-stamp/libft_lib-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/tvan-der/Desktop/Cub3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'libft_lib'"
	cd /Users/tvan-der/Desktop/Cub3d/lib/libft && /Applications/CMake.app/Contents/bin/cmake -E echo_append
	cd /Users/tvan-der/Desktop/Cub3d/lib/libft && /Applications/CMake.app/Contents/bin/cmake -E touch /Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/src/libft_lib-stamp/libft_lib-install

libft_lib-prefix/src/libft_lib-stamp/libft_lib-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/tvan-der/Desktop/Cub3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'libft_lib'"
	/Applications/CMake.app/Contents/bin/cmake -P /Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/tmp/libft_lib-mkdirs.cmake
	/Applications/CMake.app/Contents/bin/cmake -E touch /Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/src/libft_lib-stamp/libft_lib-mkdir

libft_lib-prefix/src/libft_lib-stamp/libft_lib-patch: libft_lib-prefix/src/libft_lib-stamp/libft_lib-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/tvan-der/Desktop/Cub3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'libft_lib'"
	/Applications/CMake.app/Contents/bin/cmake -E echo_append
	/Applications/CMake.app/Contents/bin/cmake -E touch /Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/src/libft_lib-stamp/libft_lib-patch

libft_lib-prefix/src/libft_lib-stamp/libft_lib-test: libft_lib-prefix/src/libft_lib-stamp/libft_lib-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/tvan-der/Desktop/Cub3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'libft_lib'"
	cd /Users/tvan-der/Desktop/Cub3d/lib/libft && /Applications/CMake.app/Contents/bin/cmake -E echo_append
	cd /Users/tvan-der/Desktop/Cub3d/lib/libft && /Applications/CMake.app/Contents/bin/cmake -E touch /Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/src/libft_lib-stamp/libft_lib-test

libft_lib-prefix/src/libft_lib-stamp/libft_lib-update: libft_lib-prefix/src/libft_lib-stamp/libft_lib-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/tvan-der/Desktop/Cub3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No update step for 'libft_lib'"
	/Applications/CMake.app/Contents/bin/cmake -E echo_append
	/Applications/CMake.app/Contents/bin/cmake -E touch /Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/src/libft_lib-stamp/libft_lib-update

libft_lib: CMakeFiles/libft_lib
libft_lib: CMakeFiles/libft_lib-complete
libft_lib: libft_lib-prefix/src/libft_lib-stamp/libft_lib-build
libft_lib: libft_lib-prefix/src/libft_lib-stamp/libft_lib-configure
libft_lib: libft_lib-prefix/src/libft_lib-stamp/libft_lib-download
libft_lib: libft_lib-prefix/src/libft_lib-stamp/libft_lib-install
libft_lib: libft_lib-prefix/src/libft_lib-stamp/libft_lib-mkdir
libft_lib: libft_lib-prefix/src/libft_lib-stamp/libft_lib-patch
libft_lib: libft_lib-prefix/src/libft_lib-stamp/libft_lib-test
libft_lib: libft_lib-prefix/src/libft_lib-stamp/libft_lib-update
libft_lib: CMakeFiles/libft_lib.dir/build.make
.PHONY : libft_lib

# Rule to build all files generated by this target.
CMakeFiles/libft_lib.dir/build: libft_lib
.PHONY : CMakeFiles/libft_lib.dir/build

CMakeFiles/libft_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libft_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libft_lib.dir/clean

CMakeFiles/libft_lib.dir/depend:
	cd /Users/tvan-der/Desktop/Cub3d/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tvan-der/Desktop/Cub3d /Users/tvan-der/Desktop/Cub3d /Users/tvan-der/Desktop/Cub3d/build /Users/tvan-der/Desktop/Cub3d/build /Users/tvan-der/Desktop/Cub3d/build/CMakeFiles/libft_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libft_lib.dir/depend


# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/tvan-der/Desktop/Cub3d/build/googletest-src"
  "/Users/tvan-der/Desktop/Cub3d/build/googletest-build"
  "/Users/tvan-der/Desktop/Cub3d/build/googletest-download/googletest-prefix"
  "/Users/tvan-der/Desktop/Cub3d/build/googletest-download/googletest-prefix/tmp"
  "/Users/tvan-der/Desktop/Cub3d/build/googletest-download/googletest-prefix/src/googletest-stamp"
  "/Users/tvan-der/Desktop/Cub3d/build/googletest-download/googletest-prefix/src"
  "/Users/tvan-der/Desktop/Cub3d/build/googletest-download/googletest-prefix/src/googletest-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/tvan-der/Desktop/Cub3d/build/googletest-download/googletest-prefix/src/googletest-stamp/${subDir}")
endforeach()

# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/tvan-der/Desktop/Cub3d/lib/libft"
  "/Users/tvan-der/Desktop/Cub3d/lib/libft"
  "/Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix"
  "/Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/tmp"
  "/Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/src/libft_lib-stamp"
  "/Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/src"
  "/Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/src/libft_lib-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/tvan-der/Desktop/Cub3d/build/libft_lib-prefix/src/libft_lib-stamp/${subDir}")
endforeach()

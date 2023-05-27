#!/bin/bash

shopt -s nullglob


# Get the current directory
directory=$(pwd)

# Get the parent directory
parent_directory=$(dirname "$directory")

# Get the parent of the parent directory
grandparent_directory=$(dirname "$parent_directory")

# Create an empty array
files=()

# Check if any files match the patterns
c_files=( "$grandparent_directory"/*.c )
h_files=( "$grandparent_directory"/*.h )


shopt -u nullglob

# Add the matching files to the array
files+=( "${c_files[@]}" "${h_files[@]}" )

# run commands

if [ ${#files[@]} -eq 0 ]; then
  echo "no .c file found"
  echo " "
  echo " "
  echo " " 
else
  # Loop through each .c file and run the betty style check
  for file in "${files[@]}"; do
    betty "$file"
  done
fi


# memory leaks

# Change to the grandparent directory
cd "$grandparent_directory" || exit

# Run gcc command for all .c files in the grandparent directory
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

valgrind --tool=memcheck --leak-check=full ./hsh

#clean 
rm hsh

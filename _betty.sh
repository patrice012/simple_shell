#!/bin/bash

# Check if there are any .c files in the current directory

shopt -s nullglob

#This enables the nullglob option in the shell, which causes patterns
#that match no files to expand to an empty string instead of themselves.
#This is useful because otherwise, if there were no .c files in the directory, the *.c
#pattern would be left as is, and the loop below would execute once with the literal string *.c.

files=( *.c )

#This creates an array called files and populates it with the names of all .c 
#files in the current directory. The *.c pattern expands to a list of filenames,
#which are stored in the files array.

if [ ${#files[@]} -eq 0 ]; then
  echo "no .c file found"
else
  # Loop through each .c file and run the betty style check
  for file in "${files[@]}"; do
    betty "$file"
  done
fi

#This checks if the files array is empty or not. If it's empty, mean there are no .c files in the current directory, it prints a message to the console saying so. Otherwise, it loops through each file in the files array and runs the betty style check on it. The ${#files[@]} expression expands to the number of elements in the files array. The for loop runs once for each element in the array, with the current element assigned to the file variable. The betty "$file" command runs the betty style check on the current file.

#run and compile all files ending with .c extension

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

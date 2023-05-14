#!/bin/bash

# Check if there are any .c files in the current directory
shopt -s nullglob
files=( *.c )
if [ ${#files[@]} -eq 0 ]; then
  echo "no .c file"
else
  # Loop through each .c file and run the betty style check
  for file in "${files[@]}"; do
    betty "$file"
  done
fi


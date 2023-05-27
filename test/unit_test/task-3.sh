#!/bin/bash

# Get the grandparent directory path
grandparent_directory=$(dirname "$(dirname "$(pwd)")")

# Change to the grandparent directory
cd "$grandparent_directory" || exit

# Run gcc command for all .c files in the grandparent directory
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o program



# Define test cases
test_cases=(
  "/bin/ls"

  "/bin/ls /var"

  "/bin/ls
/bin/ls
/bin/ls"

"/bin/ls"

""

"/bin/ls
     /bin/ls
/bin/ls
   /bin/ls     "

  "hbtn_cmd"

  "/bin/ls"

  "ls"

  "ls -l"

  ".hbtn_ls /var"

  "ls"

  ". /var"

  "../. /var"

  "../../. /var"

  "./../../. /var"

  "../../. /var"

  "./.././../////./. /var"

  "ls
     ls
ls
 ls     "


 "ls
ls
ls
/bin/ls
ls
ls
ls
/bin/ls
ls
ls"


"ls


 /bin/ls


     ls
ls
 ls     "

 "hbtn"



)

# Run tests
for ((i=0; i<${#test_cases[@]}; i++)); do
  input="${test_cases[i]}"
  
  # Run your C program
  ./program <<< "$input"
  
  # Check the exit code of the C program
  if [[ $? -eq 0 ]]; then
    echo "Test case $((i+1)): PASSED"
    echo " "
    echo " "
    echo " " 
  else
    echo "Test case $((i+1)): FAILED"
    # You can add additional error handling here if needed
  fi
done

# Cleanup (optional)
rm program

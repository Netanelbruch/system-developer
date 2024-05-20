#!/bin/bash

# Compile your C program
gcc -fprofile-arcs -ftest-coverage -o main main.c

# Get all files with .txt extension from the input folder
input_files=("tests"/*.txt)


# Loop through each input file
for input_file in "${input_files[@]}"
do
    echo "Testing with input file: $input_file"
    
    echo "Input:"
    cat "$input_file"
    echo
    
    # Run your program with the input file
    ./main < "$input_file"
    
    echo "---------------------------------------------"
done

echo "All tests completed successfully"


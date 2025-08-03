#!/bin/bash

# Check if the filename argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <filename.cpp>"
    exit 1
fi

# Get the filename from the argument
FILENAME="$1"

if [[ "$FILENAME" != *.cpp ]]; then
    FILENAME="${FILENAME}.cpp"
fi

# Remove the file extension to get the base name
BASENAME=$(basename "$FILENAME" .cpp)

# Define compile arguments (customize as needed)
COMPILE_ARGS="-Wshadow -Wall -O2 -Wno-unused-result -Wl,-stack_size,20000000 -std=c++20"

# Compile the C++ file
g++-15 $COMPILE_ARGS "$FILENAME" -o "$BASENAME"

# Check if the compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

chmod +x "$BASENAME"

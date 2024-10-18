#!/bin/bash

# Check if the executable name argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <executable_name>"
    exit 1
fi

# Get the executable name from the argument
EXECUTABLE="$1"

# Check if the executable exists
if [ ! -f "$EXECUTABLE" ]; then
    echo "Error: Executable '$EXECUTABLE' not found"
    exit 1
fi

# Run the executable
if [ -z "$2" ]; then
    ./"$EXECUTABLE"
else
    ./"$EXECUTABLE" <"$2"
fi

# Check if the executable ran successfully
echo
if [ $? -eq 0 ]; then
    echo "Execution successful: $EXECUTABLE"
else
    echo "Execution failed: $EXECUTABLE"
fi

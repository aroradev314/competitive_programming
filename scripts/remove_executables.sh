#!/bin/bash

# Loop through all files in the current directory
for file in *; do
  # Check if it is a file and is executable
  if [[ -f "$file" && -x "$file" ]]; then
    echo "Deleting executable: $file"
    rm "$file"  # Delete the executable
  fi
done

echo "Deletion complete."

#!/bin/bash

# Function to count files recursively
count_files() {
    local dir="$1"
    local count=0
    local file

    # Loop through files and directories
    for file in "$dir"/*; do
        if [ -f "$file" ]; then
            # If it's a file, increment count
            ((count++))
        elif [ -d "$file" ]; then
            # If it's a directory, recursively count files inside it
            count=$((count + $(count_files "$file")))
        fi
    done

    echo "$count"
}

# Check if directory argument is provided, otherwise use current directory
if [ $# -eq 1 ]; then
    directory="$1"
else
    directory="."
fi

# Call the function with the provided directory
count=$(count_files "$directory")

echo "Total files in $directory (including subdirectories): $count"


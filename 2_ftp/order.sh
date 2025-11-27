#!/bin/bash

# Usage: ./script.sh path/to/dir
input_dir="$1"

if [[ -z "$input_dir" ]]; then
    echo "Error: No directory provided."
    echo "Usage: $0 <directory>"
    exit 1
fi

output_file="combined.c"
> "$output_file"

declare -A results

# Collect contents indexed by file number
for file in "$input_dir"/*; do
    content=$(cat "$file")
    file_number=$(grep -oP '//file\K[0-9]+' <<< "$content")
    results[$file_number]="$content"
done

# Sort keys and write contents to output_file
for key in $(printf "%s\n" "${!results[@]}" | sort -n); do
    printf "%s\n" "${results[$key]}" >> "$output_file"
done
#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <asl_file>"
    exit 1
fi

INPUT_FILE="$1"

if [[ ! -f "$INPUT_FILE" ]]; then
    echo "File not found: $INPUT_FILE"
    exit 1
fi

echo "Testing $INPUT_FILE"

./asl "$INPUT_FILE" >tmp.t 2>tmp.err

if [ -s tmp.err ]; then
    echo "Errors found:"
    cat tmp.err
else
    echo "No errors found."
fi

#rm -f tmp.t tmp.err

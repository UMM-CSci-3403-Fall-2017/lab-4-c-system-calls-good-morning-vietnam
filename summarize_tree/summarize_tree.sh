#!/bin/bash

# used find to count the number of directories
num_dirs=$(find -L $1 -type d | wc -l)

# used find to count the number of regular files
num_regs=$(find -L $1 -type f | wc -l)

echo "There were $num_dirs directories."
echo "There were $num_regs regular files."

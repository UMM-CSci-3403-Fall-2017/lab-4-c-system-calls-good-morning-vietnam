#!/usr/bin/env bash

start_dir=$1

num_files=`find $start_dir -type f | wc -l`
num_dirs=`find $start_dir -type d | wc -l`

echo "There were $num_dirs directories."
echo "There were $num_files regular files."

#!/bin/bash

if [ $# -ne 1 ] ; then
	echo "summarize_tree.sh requires one parameter"
	exit
fi

DIR="$1"
NUM_DIRS=`find $DIR -type d | wc -l`
NUM_FILES=`find $DIR -type f | wc -l`

echo "There were $NUM_DIRS directories."
echo "There were $NUM_FILES regular files."

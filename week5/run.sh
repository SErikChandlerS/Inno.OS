#! /bin/bash

if [ $# -ne 2 ]; then
	echo $0 [filename] [N]
	exit
fi

for ((i = 0; i < $2; i++)); do
	echo `./$1`
done

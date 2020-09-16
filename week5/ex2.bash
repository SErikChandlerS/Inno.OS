#!/bin/bash
filename='numbers.txt'

if test -f "$filename.lock"
then
	rm numbers.txt.lock
fi

while true
do
	if ln -s $filename $filename.lock &> /dev/null
	then
		last=`tail -1 $filename.lock`
		last=$((last+1))
		echo $last>>$filename.lock
		rm $filename.lock
	fi
done

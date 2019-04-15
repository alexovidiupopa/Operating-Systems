#!/bin/bash


declare -A array
declare -A result
for i in "$@";do
	array[$i]=0
	result[$i]=1
done
while true; do
	echo "Read file:"
	read file
	for i in "$@";do
		for w in `cat $file`;do
			if [ $w == $i ]; then
				array[$w]=1
		fi																					                
		done
	done																								       
       	ok=0
	for i in "$@"; do
		if [ ${array[$i]} -eq ${result[$i]} ]; then																						((ok++))																									fi
	done
	if [ $ok -eq $# ]; then
		echo "Done"
		break
	fi
done

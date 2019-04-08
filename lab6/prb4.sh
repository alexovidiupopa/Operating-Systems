#!/bin/bash 

D=$1

for p in `find $D `; do
	if [ -L $p ] && [ ! -e $p ]; then
		echo "$p doesnt exist"
	else echo "$p exists"
	fi 
done


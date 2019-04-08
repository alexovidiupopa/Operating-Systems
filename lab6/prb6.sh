#!/bin/bash

D=$1

for p in `find -perm -o=w $D`; do
	if [ -d $p ]; then 
		echo "$p is a directory with write rights, not changing anything"
	else 
		echo "$p has write rights for others"
		chmod o-w $p	
		echo "$p doesnt have write rights for others anymore"
	fi
 
done


#!/bin/bash

for a in $@; do
	if test -f $a; then 
		echo "exists" 
	fi 
done

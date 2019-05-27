#!/bin/bash

while (($#>=2)); do
	old=$1
	new=$2
	for i in `find -name "*.$old"`; do 
		len=${#old}
		k=-1
		old2=$i
		while [ $k -lt $len ]; do 
			old2=${old2%?}
			((k++))	
		done
		old2+="."
		old2+=$new
		mv $i $old2	
	done
      	shift 2
done 

#!/bin/bash

D=$1 

for f in `find $D -type f`;do 
	if cat $f | grep -q '[0-9]\{5,\}'; then 
		echo $f
	fi	

done

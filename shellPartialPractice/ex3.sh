#!/bin/bash

for f in `find -type f -name '*.txt'`;do 
	total=`cat $f | wc -l`
	if [ $total -lt 10 ]; then 
		echo `cat $f`
	else 
	       	echo `head -n 5 $f`
		echo `tail -n 5 $f`
	fi	

done

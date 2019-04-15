#!/bin/bash

for i in $*;do 
	if [ -f $i ]; then 
		echo $i 
		echo `cat $i | wc -m`
		echo `cat $i | wc -l`
	elif [ -d $i ]; then 
		echo $i 
		echo `find $i | awk 'END{print NR}'`
	fi	

done

#!/bin/bash

dir=$1
nr=$2
cuv1=$3
cuv2=$4

for f in `find $dir -type f`;do
	wordc1=0
	wordc2=0
	for w in `cat $f`; do 
		if [ $w == $cuv1 ];then
			((wordc1++))
		fi
		if [ $w == $cuv2 ];then
			((wordc2++))
		fi
	done
		if [ $wordc1 -lt $nr ] && [ $wordc2 -gt $nr ];then 
			echo $f 
		fi
		
	done

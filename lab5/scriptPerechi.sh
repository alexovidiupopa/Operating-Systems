#!/bin/bash

#script that takes as arguments pairs <file,number> and checks whether file has dimension = number

while (( "$#">=2 ));do
	if [ $(stat --format=%s $1) == $2 ];then 
		echo "yes\n"
	else 
		echo "no\n"
	fi
	shift 2
done


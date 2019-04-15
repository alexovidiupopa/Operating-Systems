#!/bin/bash

D=$1 

for f in `find $D -type f -perm -u=rwx -perm -g=rx -perm -o=rx`;do 
	echo "Do you want to change rights for $f?"
	read cmd 
	if [ $cmd == "yes" ]; then 
		chmod g-x $f
		chmod o-x $f
	fi
done

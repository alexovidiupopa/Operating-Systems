#!/bin/bash

D=$1 

for f in `find $D -perm ugo=r`; do
	echo $f
	mv $f "$f.all"
done

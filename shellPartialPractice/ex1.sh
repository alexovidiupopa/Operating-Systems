#!/bin/bash

D=$1 
count=0
sum=0
for f in `find $D -type f -name '*.txt'`;do
	lines=`cat $f | wc -l`
	((count++))
	((sum+=$lines))
done
media=$((sum/lines))
echo $media

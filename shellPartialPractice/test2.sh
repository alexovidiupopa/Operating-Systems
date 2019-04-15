#!/bin/bash

for f in `find -type f -perm u=r`;do
	size=`cat $f | wc -c`
	day=`ls -l | grep $f | awk '{print $7}'`
	month=`ls -l | grep $f | awk '{print $6}'`
	time=`ls -l | grep $f | awk '{print $8}'`
	type=`file -b $f`
	echo $size $day $month $time $type > "$f.info"

done

#!/bin/bash

myDir=$1

s=""

while true ; do
	cs=""
	for P in `find $myDir`;do
		if [ -f $P ];then
			LS=`ls -l $P | sha1sum`
			content=`sha1sum $P`
		else 
			LS=`ls -l -d $P | sha1sum`
			content=`ls -l $P | sha1sum`
		fi
		cs="$cs\n$LS$content"	
	done
	if [ -n "$s" ] && [ "$cs" != "$s" ];then
		echo "Dir changed"
	fi 
	s=$cs
	sleep 1
done

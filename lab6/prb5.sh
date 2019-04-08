#!/bin/bash	
while true; do 
	processes=`ps -C "$@" | awk 'NR>1{print $1}'`
	for p in $processes;do 
		kill -9 $p
	done
	sleep 1
	done

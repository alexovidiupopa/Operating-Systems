#!/bin/bash

names=`cat who.fake | awk '{print $1}'`

for name in $names;do
	        times=`cat ps.fake | grep ^$name | wc -l`
		        echo $name $times
		done

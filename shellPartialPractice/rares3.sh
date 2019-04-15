#!/bin/bash

D=$1

for d in `find $D | grep ".log$"`; do
	        rm $d
		        mv `sort $d` $d
			        done

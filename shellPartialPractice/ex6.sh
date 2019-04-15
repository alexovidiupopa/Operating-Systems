#!/bin/bash

while (( "$#">=3 ));do
        nr=$3
        fis=$1
	cuv=$2
	rez=`cat $fis | grep -c $cuv`
	if [ $rez -eq $nr ];then
		echo -e `cat $fis`
	fi
	shift 3
done

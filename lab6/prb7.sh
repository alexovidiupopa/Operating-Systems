#!/bin/bash 

file=$1
stringFinal=""
string=`awk '{print $1}' $file`

for p in $string;do
	stringFinal+=$p
	stringFinal+="@scs.ubbcluj.ro"
	stringFinal+=","
done;
stringFinal=${stringFinal%?}
echo $stringFinal

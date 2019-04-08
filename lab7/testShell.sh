#!/bin/bash
#Se da un cuvant ca parametru. Sa se afiseze toate fisierele din directory+subdirectories care contin 
#cuvantul dat de cel putin 3 ori. 
word=$1

for f in `find -type f`;do
        words=`cat $f | awk '{for (i=0;i<NF;i++){print $i}}'`
        wordc=0
        for w in $words;do
                if [ $w == $word ]; then
                        ((wordc++))
                fi
        done
        if [ $wordc -gt 2 ];then
                echo $f contains the word at least 3 times
        fi

done

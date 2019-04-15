#Sa se scrie un fisier de comenzi care va afisa toate numele de fisiere dintr-un director dat ca parametru
#si din subdirectoarele sale, care au numele mai scurte de 8 caractere.
#Pentru acestea, daca sunt fisiere text, li se vor afisa primele 10 linii.

#!/bin/bash

D=$1 

for f in `ls -R $D`;do
	len=${#f}
	if [ $len -lt 8 ]; then 
		echo $f
	fi
done

#Sa se afiseze pentru fiecare fisier din linia de comanda linia care apare de cele mai multe ori,
#afisarea facandu-se in ordinea decsrescatoare a numarului de aparitii. (comenzi: sort, uniq, head).

#!/bin/bash

for i in $*;do
	if [ -f $i ];then
		echo `cat $i | uniq -c | sort -r | head -n 1`
	fi
done

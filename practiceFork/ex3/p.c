/*Sa se scrie un program c (P) care genereaza un numar random (NR) intre
5000 si 10000, apoi creeaza un fiu (C). P ii trimite lui C numarul NR prin
pipe. C scade din NR un numar random intre 900 si 1000 si ii trimite
rezultatul lui P. P scade la randul lui un numar random intre 900 si 1000
din NR si trimite rezultatul lui C. Fiecare proces va afisa un mesaj cu
numarul primit si numarul trimis. Algoritmul se repeta pana cand unul din
procese primeste un numar mai mic decat -10000, moment in care acel proces
afiseaza un mesaj.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
int main(int argc, char **argv){
	srand(time(NULL));
	int r;
	int p2c[2],c2p[2];
	pipe(p2c);
	pipe(c2p);
	if (fork()==0){ //Child process
			close(p2c[1]);
			close(c2p[0]);
			while(read(p2c[0],&r,sizeof(int)) && r>-10000){
				int newRand = rand()%(1000+1-900)+900;
				r-=newRand;
				printf("C:%d->%d\n",r+newRand,r);
				write(c2p[1],&r,sizeof(int));
			}
			if (r<=-10000){
				printf("C- Done");
				return 0;
			}
			close(c2p[1]);
			close(p2c[0]);
			exit(0);
	}
	r = rand()%( 10000 + 1 - 5000 )+5000;
	write(p2c[1],&r,sizeof(int));
	while (read(c2p[0],&r,sizeof(int)) && r>-10000){
		int newRand = rand()%(1000+1-900)+900;
		r-=newRand;
		printf("P:%d->%d\n",r+newRand,r);
		write(p2c[1],&r,sizeof(int));
	}
	if (r<=-10000){
		printf("P- Done");
		return 0;
	}
	close(p2c[0]);
	close(c2p[1]);
	wait(0);
	return 0;
}

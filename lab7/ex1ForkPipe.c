//program c in care generezi un nr random. 1 fork(), scrii prin pipe nr fiului. fiul il dubleaza si il
//scrie inapoi la parinte. + afisare
//read man 2 pipe
//error handling

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv){
	srand(time(NULL));
	int p2c[2],c2p[2],nr;
	pipe(p2c);pipe(c2p);
	if (fork()==0){
		read(p2c[0],&nr,sizeof(int));
		close(p2c[0]);
		nr*=2;
		write(c2p[1],&nr,sizeof(int));		
		exit(0);
	}
	nr = rand() % 1000;
	write(p2c[1],&nr,sizeof(int));
	wait(0);
	printf("%d\n",nr);	
	close(c2p[1]);
	read (c2p[0],&nr,sizeof(int));
	close(c2p[0]);
	printf("%d\n",nr);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc,char **argv){
	int a[101],n=0,aux;
	scanf("%d",&aux);
	while (aux>0){
		a[n++]=aux;
		scanf("%d",&aux);
	}
	int i,x;
	int c2p[2],p2c[2];
	for(i=0;i<n;i++){
		pipe(c2p);
		if(fork()==0){
			close(c2p[0]);
			write(c2p[1],&a[i],sizeof(int));
			close(c2p[1]);
			exit(0);
		}
	}
	close(c2p[1]);
	read(c2p[0],&x,sizeof(int));
	close(c2p[0]);
	wait(0);
	printf("%d ",x);
	return 0;
}

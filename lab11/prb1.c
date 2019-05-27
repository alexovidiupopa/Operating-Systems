//program cu 2 tipuri de threaduri
//A-1 nr random/sec de 10 ori
//B-printeaza valoarea generata de A de 2 ori pe secunda de 20 de ori
//executie cu mai multe threaduri de fiecare tip.

#include <stdio.h>
#include <pthread.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void *genereaza(void *a)
{
	
	int* temp=(int*)a;
	int i;
	for(i=0;i<10;i++){
		*temp=rand()%1000;
		//a=(void*)temp;
		sleep(1);
	}
	return NULL;
}

void *printeaza(void *a)
{
	int *nr=(int*)a;
	int i;
	for(i=0;i<20;i++){
		printf("%d\n",*nr);
		usleep(500000);
	}
	return NULL;
}

int main(int argc, char **argv){
	srand(time(NULL));
	pthread_t a[10];
	pthread_t b[10];
	int nr=0,i;
	pthread_create(a,NULL,genereaza,(void*)&nr);
	pthread_create(b,NULL,printeaza,(void*)&nr);
	pthread_join(a,NULL);
	pthread_join(b,NULL):
	return 0;
}

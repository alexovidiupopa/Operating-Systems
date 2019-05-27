//program cu 2 tipuri de threaduri
//A-1 nr random/sec de 10 ori
//B-printeaza valoarea generata de A de 2 ori pe secunda de 20 de ori
//executie cu mai multe threaduri de fiecare tip+sincronizare cu mutex simplu.

#include <stdio.h>
#include <pthread.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

pthread_mutex_t mtx;

void *genereaza(void *a)
{
	
	int* temp=(int*)a;
	int i;
	for(i=0;i<10;i++){
		pthread_mutex_lock(&mtx);
		*temp=rand()%1000;
		printf("Generated:%d\n",*temp);
		pthread_mutex_unlock(&mtx);
		sleep(1);
	}
	return NULL;
}

void *printeaza(void *a)
{
	int *nr=(int*)a;
	int i;
	for(i=0;i<20;i++){
		pthread_mutex_lock(&mtx);
		printf("Printed:%d\n",*nr);
		pthread_mutex_unlock(&mtx);
		usleep(500000);
	}
	return NULL;
}

int main(int argc, char **argv){
	srand(time(NULL));
	pthread_t a[10];
	pthread_t b[10];
	pthread_mutex_init(&mtx,NULL);
	int nr=0,i;
	for(i=0;i<10;i++){
		pthread_create(&a[i],NULL,genereaza,(void*)&nr);
	}
	for(i=0;i<10;i++){
		pthread_create(&b[i],NULL,printeaza,(void*)&nr);
	}
	for(i=0;i<10;i++){
		pthread_join(a[i],NULL);
	}
	for(i=0;i<10;i++){
		pthread_join(b[i],NULL);
	}
	pthread_mutex_destroy(&mtx);
	return 0;
}

//program cu 2 tipuri de threaduri
//A-1 nr random/sec de 10 ori
//B-printeaza valoarea generata de A de 2 ori pe secunda de 20 de ori
//executie cu mai multe threaduri de fiecare tip+sincronizare cu rwlock..

#include <stdio.h>
#include <pthread.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

pthread_rwlock_t rwl;

void *genereaza(void *a)
{
	
	int* temp=(int*)a;
	int i;
	for(i=0;i<10;i++){
		pthread_rwlock_wrlock(&rwl);
		*temp=rand()%1000;
		printf("Generated:%d\n",*temp);
		//sleep(1);
		pthread_rwlock_unlock(&rwl);
		sleep(1);
	}
	return NULL;
}

void *printeaza(void *a)
{
	int *nr=(int*)a;
	int i;
	for(i=0;i<20;i++){
		pthread_rwlock_rdlock(&rwl);
		printf("Printed:%d\n",*nr);
		//usleep(500000);
		pthread_rwlock_unlock(&rwl);
		usleep(500000);
	}
	return NULL;
}

int main(int argc, char **argv){
	srand(time(NULL));
	pthread_t a[10];
	pthread_t b[10];
	pthread_rwlock_init(&rwl,NULL);
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
	pthread_rwlock_destroy(&rwl);
	return 0;
}

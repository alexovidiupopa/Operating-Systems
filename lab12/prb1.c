//un program cu 7 thr, fiecare genereaza 100 nr random pana in 1000, si pt fiecare nr random generat il aduna intr un array care are 10 pozitii. il aduna pe pozitia nr%10. se afiseaza la final sirul.

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


int numbers[10];
pthread_rwlock_t lock;

void *f(void *arg){
	int i;
	for(i=0;i<100;i++){
		int nr=rand()%1000;
		pthread_rwlock_wrlock(&lock);
		numbers[nr%10]+=nr;
		pthread_rwlock_unlock(&lock);
	}
	return NULL;
}


int main(int argc, char **argv){
	pthread_t t[7];
	srand(time(NULL));
	pthread_rwlock_init(&lock,NULL);
	int i;
	for(i=0;i<7;i++){
		pthread_create(&t[i],NULL,f,NULL);
	}
	for(i=0;i<7;i++){
		pthread_join(t[i],NULL);
	}
	for(i=0;i<10;i++){
		printf("Poz %d - val %d\n",i,numbers[i]);
	}
	pthread_rwlock_destroy(&lock);
	return 0;
}

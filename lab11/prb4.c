//3 threaduri care incrementeaza fiecare de 10 ori. un al 4-lea thread e semnalat de unul dintre cele 3 cand o valoare a ajuns la 20. folosind conditional variables
//

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mtx;
void *increment(void *a)
{
	int *temp = (int*)a;
	int i;
	for(i=0;i<10;i++)
	{
		
		*temp++;
	}
	return NULL;
}
int main(int argc,char **argv){
	pthread_t inc[3];
	pthread_t check;

	int i,n=0;
	pthread_create(&check,NULL,NULL,NULL);
	for(i=0;i<3;i++){
		pthread_create(&inc[i],NULL,increment,(void*)n);
	}
	for(i=0;i<3;i++){
		pthread_join(inc[i],NULL);
	}
	return 0;
}

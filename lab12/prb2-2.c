#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

pthread_mutex_t mtx;

int nr=0;
FILE *print;

int divCount(long int x){
	int d,count=0;
	for(d=1;d*d<x;d++){
		if(x%d==0)
		{
			count+=2;
		}
	}
	if (d*d==x)
		count++;
	return count;
}

void *f(void *a){
	long int* no = (long int*)a;
	pthread_mutex_lock(&mtx);
	//nr+=divCount(*no);
	fprintf(print,"%d ",divCount(*no));
	pthread_mutex_unlock(&mtx);
	return NULL;
}


int main(int argc, char **argv){
	int fifo,i;
	fifo=open("fifo",O_RDONLY);
	int n;
	read(fifo,&n,4);
	long int fileSizes[n];
	pthread_t t[n];
	for(i=0;i<n;i++){
		read(fifo,&fileSizes[i],8);
	}
	
	pthread_mutex_init(&mtx,NULL);
	print = fopen("division_count.txt","w");
	for(i=0;i<n;i++){
		pthread_create(&t[i],NULL,f,(void*)&fileSizes[i]);
	}
	for(i=0;i<n;i++){
		pthread_join(t[i],NULL);
	}
	pthread_mutex_destroy(&mtx);
	fclose(print);
	return 0;
}

//Sa se scrie un program c care citeste o matrice de la tastatura.
//Folosind thread-uri, programul va calcula suma numerelor de pe fiecare
//coloana din matrice, un thread va calcula suma pe o singura coloana.+ suma totala global
//sync si async

#include <stdio.h>
#include <pthread.h>

int s;

typedef struct data{
	int **a;
	int n,m;
	int j;
};

void* f(data *x){
	int i,localS=0;
	for(i=0;i<n;i++){
		localS+=a[i][j];
	}
	printf("Col %d: %d\n",j,localS);
	pthread_mutex_lock(&mtx,NULL);
	s+=localS;
	pthread_mutex_unlock(&mtx,NULL);
	return NULL;
}
int main(int argc, char **argv){
	int i,j;
	pthread_t t[10];
	pthread_mutex_init(&mtx,NULL);
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	for(j=0;j<m;j++){
		pthread_create(&t[j],NULL,f,j);
	}
	for(j=0;j<m;j++){
		pthread_join(t[j],NULL);
	}
	pthread_mutex_destroy(&mtx);
	printf("Final sum: %d\n",s);
	return 0;
}

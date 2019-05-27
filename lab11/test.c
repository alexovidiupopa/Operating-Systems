#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mtx;
int count;
struct date{
	int x,y;
};


int prim(int x){
	if(x<2 || (x>2 && x%2==0))
		return 0;
	int d;
	for (d=3;d*d<=x;d+=2){
		if(x%d==0)
			return 0;
	}
	return 1;
}

void *f(void *a)
{
	struct date* d = (struct date*) a;
	int result = prim(d->x+d->y);
	pthread_mutex_lock(&mtx);
	count+=result;
	pthread_mutex_unlock(&mtx);
	return NULL;
}

int main(int argc,char **argv){
	int n;
	struct date d[100];
	pthread_t t[100];	
	pthread_mutex_init(&mtx,NULL);
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&d[i].x);
		scanf("%d",&d[i].y);
	}
	for(i=0;i<n;i++){
		pthread_create(&t[i],NULL,f,&d[i]);
	}
	for(i=0;i<n;i++){
		pthread_join(t[i],NULL);
	}
	pthread_mutex_destroy(&mtx);
	printf("Result:%d\n",count);
	return 0;
}

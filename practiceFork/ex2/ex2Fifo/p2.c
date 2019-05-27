#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int prim(int x){
	if(x<2 || x>2 && x%2==0)
		return 0;
	int d;
	for(d=3;d*d<=x;d+=2){
		if(x%d==0){
			return 0;
		}
	}
	return 1;
}

int main(int argc,char**argv){
	int fifo,res,i,n;
	fifo = open("fifo",O_RDONLY);
	if(fifo!=-1){
		read(fifo,&n,4);
		for(i=0;i<n;i++){
			read(fifo,&res,sizeof(int));
			if(prim(res)){
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
		}
		close(fifo2);

	}
	return 0;
}

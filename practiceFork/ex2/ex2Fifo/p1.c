#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc,char **argv){
	int fifo,i, a[101],n=0,aux;
	scanf("%d",&aux);
	while (aux>0){
		a[n++]=aux;
		/*if(mkfifo("fifo",0600)==0){
			                        fifo = open("fifo",O_WRONLY);
						                        write(fifo,&aux,sizeof(int));
									                        close(fifo);
												                }
		                else {
					                        execlp("rm","rm","fifo",NULL,NULL);
								                }*/
		scanf("%d",&aux);
	}
	if(mkfifo("fifo",0600)==0){
		fifo = open("fifo",O_WRONLY);
		write(fifo,&n, sizeof(int));
		for(i=0;i<n;i++){
			write(fifo,&a[i],sizeof(int));
			
		}
		close(fifo);
	
	}

	else {
		printf("remove the fifo");
	}
	return 0;
}

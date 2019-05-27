//Create two programs A and B.
//Program A receives as command line arguments
//multiple file names.
//For each file name, it creates a child process
//that calculates the file size in bytes and sends it back to the parent.
//After all the file sizes have been computed,
//process A sends them via fifo one by one to process B.
//Process B reads the file sizes and, after all numbers are received,
//creates a thread for each one that counts the number of divisors of the
//number
//and writes it in a file named "divisor_count".
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc,char**argv){
	long int fileSizes[argc-1];
	int i,fifo;	
	int c2p[2];
	for(i=0;i<argc-1;i++){
		pipe(c2p);
		if(fork()==0){
			close(c2p[0]);
			FILE *fp;
			long int size=0;
			fp=fopen(argv[i+1],"r");
			fseek(fp,0,SEEK_END);
			size=ftell(fp);
			write(c2p[1],&size,8);
			close(c2p[1]);
			exit(0);
		}
		close(c2p[1]);
		read(c2p[0],&fileSizes[i],8);	
		close(c2p[0]);
		//wait(0);
	}

	for(i=0;i<argc-1;i++){
		printf("%ld\n",fileSizes[i]);
	}
	if (mkfifo("fifo",0666)==0){
		fifo = open("fifo",O_WRONLY);
		argc--;
		write(fifo,&argc,sizeof(int));
		for(i=0;i<argc;i++){
			write(fifo,&fileSizes[i],8);
		}
	}
	else {printf("Remove the fifo");}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
int main(int argc, char **argv){
	int shm;
	char *s;
	shm = shmget(2602,0,0);
	s = shmat(shm,0,0);
	printf(s);
	return 0;
}

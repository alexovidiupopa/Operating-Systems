#include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char **argv){
	int shm;
	char s[10];
	
	strcpy(s,argv[1]);
	shm = shmget(2602, sizeof(char*),IPC_CREAT | 0600);
//	s = shmat(shm,0,0);
	shmdt(s);
	shmctl(shm,IPC_RMID,0);
	return 0;
}

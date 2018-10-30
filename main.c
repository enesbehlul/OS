#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char *argv[], char ** envp){
	int i,fv,w,status;
	char *newargv[3];
	newargv[0]="18";
	newargv[1]="2";
	newargv[2]=NULL;
	i = execve("div",newargv,envp);
	//printf("i = %d Get pid: %d parent id: %d\n",i, getpid(),getppid());
	//w = wait(&status);
	printf("i = %d Get pid: %d parent id: %d \n", i, getpid(),getppid());
	return 0;
}

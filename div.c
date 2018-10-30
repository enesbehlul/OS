#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char *argv[], char ** envp){
	printf("Sonuc = %d\n",atoi(argv[0])/atoi(argv[1]));
	return 0;
}
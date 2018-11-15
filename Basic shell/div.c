#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char *argv[], char ** envp){
	int bolunen = atoi(argv[0]), bolen = atoi(argv[1]);
	printf("Sonuc: %d/%d = %d\n",bolunen, bolen, bolunen/bolen);
	return 0;
}
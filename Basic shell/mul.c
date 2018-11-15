#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(int argc, char *argv[], char ** envp){
	int carpim1 = atoi(argv[0]), carpim2 = atoi(argv[1]);
	printf("Sonuc: %d*%d = %d\n",carpim1, carpim2, carpim1*carpim2);
	return 0;
}
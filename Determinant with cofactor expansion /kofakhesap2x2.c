#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char *argv[], char **envp)
{
	printf("nasilsin\n");
	int i,j,k,satir,sutun;
	int **ikilik = (int **)malloc(2 * sizeof(int *));
	for (k = 0; k < 2; k++)
		ikilik[k] = (int *)malloc(2 * sizeof(int));
	
	
	int number, count = 0;
	for (i = 0; i <  2; i++){
		for (j = 0; j < 2; j++){
			char str[10];
			strcpy(str, (argv[count++]));
			number = atoi(str);
			ikilik[i][j] = number;
		}
	}
	
	for (i = 0; i <  2; i++)
		for (j = 0; j < 2; j++)
			printf("%d ", ikilik[i][j]);
	
	satir = 2;
	sutun = 3;
	int kofaktor;
	kofaktor = ikilik[0][0]*ikilik[1][1] - ikilik[0][1]*ikilik[1][0];
	printf("\n%d\n", kofaktor);

	return 0;
}
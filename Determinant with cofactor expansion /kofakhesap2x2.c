#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

int main()
{

	int i,j,k,satir,sutun;
	
	
	char dizi[2][2];
	read(3,&dizi, sizeof(char)*4);
	for (i = 0; i <  2; i++){
		for (j = 0; j < 2; j++){
			printf("%d ", dizi[i][j]);
		}
		puts("");
	}

	satir = 2;
	sutun = 3;
	int kofaktor;
	kofaktor = dizi[0][0]*dizi[1][1] - dizi[0][1]*dizi[1][0];
	printf("\n%d\n", kofaktor);
	write(4,&kofaktor, sizeof(int));

	return 0;
}
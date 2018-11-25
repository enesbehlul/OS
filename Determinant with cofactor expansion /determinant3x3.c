#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define SATIR 3
#define SUTUN 3

int** mallocMultiDarray(int satir, int sutun){
	int k;
	int **matris = (int **)malloc(sutun * sizeof(int *));
	for (k = 0; k < sutun; k++)
		matris[k] = (int *)malloc(satir * sizeof(int));
	return matris;
}

void createTwoDarray(int **matris, int **yeniMatris, int sSatir, int sSutun){
	//2x2 matris oluşturma
	int satir = 0, sutun = 0, i, j, k, count = 0; 
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (i == sSatir)
				break;
			if (j != sSutun)
			{
				yeniMatris[satir][sutun] = matris[i][j];
				sutun++;
			}
		}
		if(j == 3)
			satir++;
		sutun = 0;
	}	
}

void create3Darray(int **matris){
	int i,j,count=0;
	int sayilar[9] = {1,2,-1,0,1,-1,-1,3,1};
	for(i = 0; i < SATIR; i++)
		for(j = 0; j < SUTUN; j++)
			*(*(matris+i)+j) = sayilar[count++];
}

void printMatrix(int **matris, int satir, int sutun){
	int i,j;
	for (i = 0; i <  satir; i++){
		for (j = 0; j < sutun; j++){
			printf("%d ", matris[i][j]);
		}
		printf("\n");
	}
}
int rastgeleSatirOku(){
	int fd1;
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);
    char rakamStr[10];
    fd1 = open(myfifo,O_RDONLY);
	read(fd1, rakamStr, 10);
    printf("User1: %s\n", rakamStr);
    close(fd1);
    int rakam = atoi(rakamStr);
    return rakam;
}
char** argumanListesiOlustur(){
	int i;
	char **newargv = (char **) calloc (15, sizeof (char *));
	for (i = 0; i < 15; i++){
		newargv[i] = (char *) calloc (15, sizeof (char));
	}
	return newargv;
}
char** int2dMatrixToCharArray(int **matris, int satir, int sutun){
	int i,j,number,count = 0;
	char **sayilar = (char **) calloc (15, sizeof (char *));
	for (i = 0; i < 15; i++){
		sayilar[i] = (char *) calloc (15, sizeof (char));
	}
	for (i = 0; i < satir; i++)
	{
		for (j = 0; j < sutun; j++)
		{	
		
			number = matris[i][j];
			sprintf(sayilar[count++], "%d", number);
			
		}
	}
	return sayilar;
}
int main(int argc, char *argv[], char **envp)
{	
	//3x3 matris 2d array memory allocation
	int **matris = mallocMultiDarray(SATIR, SUTUN);
	
	//matris olusturma
	create3Darray(matris);
	
	int exec, i,j;
	int fv = fork();
	if (fv == 0)
		exec = execve ("satsutsec", argv, envp);
	//else
		//sleep(1);

	int rastgeleSatir = rastgeleSatirOku();
	
	//2x2 matris mem allac
	int **yeniMatris = mallocMultiDarray(2, 2);
	

	createTwoDarray(matris, yeniMatris, 1, 2);
	
	//execve icin arguman listesi
	char **newargv = int2dMatrixToCharArray(yeniMatris,2,2);
	newargv[5] = NULL;
	
	int fv2 = fork();
	int exec2;
	if (fv2==0)
		exec2 = execve ("kofakhesap", newargv, envp);
	
	printf("naber\n");
	return 0;
}
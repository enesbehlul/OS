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
	int sayilar[9] = {1,2,1,3,1,0,2,1,5};
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
	int i,j,count = 0;
	char **sayilar = (char **) calloc (15, sizeof (char *));
	for (i = 0; i < 15; i++){
		sayilar[i] = (char *) calloc (15, sizeof (char));
	}
	for (i = 0; i < satir; i++)
	{
		for (j = 0; j < sutun; j++)
		{	
		
			sprintf(sayilar[count++], "%d", matris[i][j]);
			
		}
	}
	return sayilar;
}

int main()
{	
	//3x3 matris 2d array memory allocation
	int **matris = mallocMultiDarray(SATIR, SUTUN);
	
	//matris olusturma
	create3Darray(matris);
	
	int exec, i,j;
	int fv = fork();
	if (fv == 0){
		exec = execv("satsutsec", NULL);
	}
	//else
	//	_exit(1);

	int rastgeleSatir = rastgeleSatirOku();
	
	//2x2 matris mem allac
	int **yeniMatris = mallocMultiDarray(2, 2);
	

	char temp[2][2];
	char **newargv;
	int p,r;
	int fd[2];
	int pid, line;
	if (pipe(fd)<0){
		perror("pipe");
		exit(1);
	}
	int toplamKofaktor = 0;
    for(i = 0; i < 3; i++){
	    createTwoDarray(matris, yeniMatris, rastgeleSatir, i);
		printf("--------\n");
		for (p = 0; p < 2; ++p){
			for (r = 0; r < 2; ++r){
				temp[p][r] = yeniMatris[p][r];
			}
		}
		int f = fork();
		if (f == 0){
			write(fd[1],&temp, sizeof(char)*4);
			f = execv("kofakhesap", NULL);
		}
		else{
			wait(&f);
			int kofaktor = 0;
			read(fd[0], &kofaktor, sizeof(int));
			printf("%d\n",kofaktor);
			if ((i+rastgeleSatir) % 2 == 1){
				kofaktor *= -1;
			}
			kofaktor *= matris[rastgeleSatir][i];
			toplamKofaktor += kofaktor;
		}
		printf("\n%d\n",toplamKofaktor);
	}
	return 0;
		
}

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include <ctype.h>

int main(int argc, char *argv[], char ** envp){
	
	int rakam = atoi(argv[0]);
	if (!(rakam == 0 && argv[0][0] != '0'))
	{
		char *rakamlar[10] = {"sifir","bir","iki","uc","dort","bes","alti","yedi","sekiz","dokuz"};
		if (rakam<=9 && rakam>=0)
			printf("Cikti: %s\n",rakamlar[rakam]);
		else
			puts("sayi degil rakam giriniz.");
	}
	else
		puts("Karakter girmeyiniz.");
	return 0;
}

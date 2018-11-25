#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[], char **envp)
{
	srand(time(NULL));
	int r;
	r = ( rand() % 3 );
	printf("%d. satir rastgele secildi.\n", r);
	

	int fd;
 
    char * myfifo = "/tmp/myfifo";
 
    mkfifo(myfifo, 0666);
 
    char rakam[10];
    sprintf(rakam, "%d", r);
    fd = open(myfifo, O_WRONLY);
 	write(fd, rakam, strlen(rakam)+1);
    close(fd);
    _exit(1);
	return 0;
}
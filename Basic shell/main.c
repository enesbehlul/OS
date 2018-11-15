#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int
main (int argc, char *argv[], char **envp)
{
  char programlar[6][30] = { {0} };
  strncpy (programlar[0], "exit", strlen ("exit") + 1);
  strncpy (programlar[1], "mul", strlen ("mul") + 1);
  strncpy (programlar[2], "div", strlen ("div") + 1);
  strncpy (programlar[3], "cat", strlen ("cat") + 1);
  strncpy (programlar[4], "rakam", strlen ("rakam") + 1);
  char str[256];
  char exit[6];
  int i,ii, j, sayac;
  strcpy (exit, "exit\n");

  while (1) {
      printf ("myshell>>");
      fgets (str, sizeof (str), stdin);
      //exit komutu girildiğinde sonlandır
      if (strncmp (exit, str, 4) == 0)
		return 0;

	  //girilen komutu sozcuklere ayirma
      char *token = strtok (str, " ");
      char str2[12][30];

      i = 0;
      //ayrilan sozcukleri arguman listesinde kullanabilmek uzere başka bir diziye atama
      while (token != NULL) {
	  	strcpy (str2[i], token);
	  	token = strtok (NULL, " ");
	  	i++;
	  }
      sayac = 0;
      for (i = 0; i < 6; i++) {
		  if (strcmp (str2[0], programlar[i]) != 0) {
		      sayac++;
		  }
		  if (sayac == 6){
		      puts ("Yanlis komut.");
		  }
		  if (strcmp (str2[0], programlar[i]) == 0) {
		      char **newargv = (char **) calloc (15, sizeof (char *));

		      for (ii = 0; ii < 15; ii++){
			  	newargv[ii] = (char *) calloc (15, sizeof (char));
			  }
		      int fv;
		      fv = fork ();
		      // child process icinde program cagrisi
		      if (fv == 0 && (strcmp (str2[0], "clear") != 0)) {
				  if (strcmp (str2[0], "cat") == 0) {
				      strcpy (newargv[0], "cat");
				      strcpy (newargv[1], str2[1]);
				      newargv[2] = NULL;
				      j = execve ("/bin/cat", newargv, envp);
				    }
				  else{
				  	strcpy (newargv[0], str2[1]);
				  	strcpy (newargv[1], str2[2]);
				  	newargv[2] = NULL;
				    j = execve (str2[0], newargv, envp);
				  }
				  _exit(1);
			   }
			   //wait komutu kullanmadan rakam programini cagirma(&& den sonrasını koymak, rakam komutu bir kere kullanıldığında konsolda diğer 
			   // komutlar tekrar girilince wait gerçekleşmiyormuş gibi bir görüntü oluyor.)
		      else if (fv != 0 && (strcmp (str2[0], "rakam") != 0)){
			  	wait (&j);
			  }
	      }
		}
  }
  return 0;
}
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUESTION "cli2serv" 
#define REPONSE "serv2cli"

int main(void){
	int fdq, fdr, res;
	char quest[11];
	char rep[11];
	unlink(QUESTION); 
	unlink(REPONSE); //unlink : detruit un nom dans le systeme de fichier

/* Creation fifos*/
	if (mkfifo(QUESTION, 0644) != 0 || mkfifo(REPONSE, 0644) == -1) {
		perror("Impossible creer fifos");  
		exit(2);
	}

	fdq = open(QUESTION, O_RDONLY);
	fdr = open(REPONSE, O_WRONLY);
	
	if (strcmp(quest, "Ciao") == 0) 
		{
			strcpy(rep, "Bye");
			write(fdr, rep, 10);
		}
	res = a+b;
	sprintf(rep, "%d", res);
	write(fdr, rep, 10);
	close(fdq);    
	close(fdr);
	unlink(QUESTION);    
	unlink(REPONSE);
	exit(0);
}

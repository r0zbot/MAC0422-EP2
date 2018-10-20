/* ######################################################## */
/* ###########----------Codigo Adicionado---------######### */
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <lib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	int filho;
	errno = 0;
	printf("Chamando chpriority() num processo qualquer (nao filho)...\n");
	printf("chpriority retornou %d\n", chpriority(56, 14));
	filho = fork() ;
	if(!filho){
		/*filho*/
		sleep(100);
	}
	else{
		/*pai*/
		printf("Chamando chpriority() no filho com prioridade 256 (invalida)...\n");
		printf("chpriority retornou %d\n", chpriority(filho, 256));
		printf("Chamando chpriority() no filho com prioridade 14 (invalida)...\n");
		printf("chpriority retornou %d\n", chpriority(filho, 14));
		sleep(100);
	}
	printf("errno %d\n", errno);
	return 0;
}
/* ######################################################## */
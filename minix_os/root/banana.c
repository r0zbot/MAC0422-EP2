/* ######################################################## */
/* ###########----------Codigo Adicionado---------######### */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int arq, arq2, arq_ruim;
	arq = open_tmp("pera", "a");
	arq_ruim = open_tmp("uva", "a");
	if (arq_ruim != -1){
		printf("fuck, o ruim deu bom %d\n", arq_ruim);
	}

	arq2 = open("castelo", O_CREAT | O_WRONLY);
	printf("pointer: %d \n", arq);
	printf("pointer2: %d \n", arq2);
	sleep(10);
	return 0;
}

/* ######################################################## */
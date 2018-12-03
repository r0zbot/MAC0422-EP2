#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int arq, arq2;
	arq = open_tmp("abacaxi", "a");
	arq2 = open("castelo", O_CREAT | O_WRONLY);
	printf("pointer: %d \n", arq);
	printf("pointer2: %d \n", arq2);
	fprintf(arq2, "Mexerica!\n");
	return 0;
	close(arq2);
	fprintf(arq, "Mexerica!\n");
	printf("pointer: %d \n", arq);
	return 0;
}

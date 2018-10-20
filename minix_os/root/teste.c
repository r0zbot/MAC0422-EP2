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
	
	printf("chpriority Retornou %d\n", chpriority(56, 14));
	filho = fork() ;
	if(!filho){
		sleep(100);
	}
	else{
		printf("chpriority Retornou %d\n", chpriority(filho, 14));
		sleep(100);
	}
	printf("errno %d\n", errno);
	return 0;
}

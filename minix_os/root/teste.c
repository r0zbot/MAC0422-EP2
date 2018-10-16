#include <sys/resource.h>
#include <stdio.h>
#include <lib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	errno = 0; 
	printf("chpriority Retornou %d\n", chpriority(56, 6));
	printf("errno %d\n", errno);
	errno = 0;
	return 0;
}

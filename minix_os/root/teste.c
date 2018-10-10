#include <sys/resource.h>
#include <stdio.h>
#include <lib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	errno = 0; 
	printf("chpriority Retornou %d\n", chpriority(123, 456));
	printf("errno %d\n", errno);
	errno = 0;
	printf("chpriority Retornou %d\n", _syscall(PM_PROC_NR, CHPRIORITY, 0));
	printf("errno %d\n", errno);
	errno = 0;
	printf("setpriority Retornou %d\n", setpriority(PRIO_PROCESS, 56, 6));
	printf("errno %d\n", errno);
	errno = 0;
	printf("setpriority Retornou %d\n", setpriority(1, 1, 1));
	printf("errno %d\n", errno);
	return 0;
}

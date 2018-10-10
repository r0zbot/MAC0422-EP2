#include <sys/resource.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("Retornou %d\n", chpriority(123, 456));
	return 0;
}

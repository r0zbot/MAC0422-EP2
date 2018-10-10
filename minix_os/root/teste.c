#include <resource.h>
#include <sys/resource.h>

int main(int argc, char const *argv[])
{
	printf("Retornou %d\n", chpriority(123, 456));
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	uint64_t test;
	uint16_t *it;

	test = 0;
	it = (uint16_t *)&test;
	it[1] = 1;
	printf("%llu\n", test);

	uint16_t test2[4];
	test2[0] = 0;
	test2[1] = 1;
	test2[2] = 0;
	test2[3] = 0;
	printf("%llu\n", *(uint64_t*)test2);

	uint16_t *test3 = malloc(sizeof(uint16_t) * 4);
	test3[0] = 0;
	test3[1] = 1;
	test3[2] = 0;
	test3[3] = 0;
	printf("%llu\n", *(uint64_t*)test3);

	return 0;
}

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
	printf("int %lu %d\nfloat %lu %f\ndouble %lu %f", sizeof(a), a, sizeof(b), b, sizeof(c), c);
	return 0;
}
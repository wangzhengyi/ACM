#include <stdio.h>
#include <stdlib.h>

typedef int (*fun)(int);

int final_solution(int n)
{
	return 0;
}

int iteration_solution(int n)
{
	static fun f[2] = {final_solution, iteration_solution};

	return n + f[!!n](n - 1);
}

int main(void)
{
	int n, result;

	while (scanf("%d", &n) != EOF) {
		result = iteration_solution(n);
		printf("%d\n", result);
	}

	return 0;
}

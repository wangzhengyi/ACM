#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 33

void recursionN(int n)
{
	int left, cnt = 0;

	while (pow(2, cnt) <= n) {
		cnt ++;
	}

	cnt -= 1;

	if (cnt == 0) {
		printf("2(0)");
	} else if (cnt == 1) {
		printf("2");
	} else {
		printf("2(");
		recursionN(cnt);
		printf(")");
	}

	left = n - pow(2, cnt);

	if (left > 0) {
		printf("+");
		recursionN(left);
	}
}

int main(void)
{
	int n;

	while (scanf("%d", &n) != EOF) {
		recursionN(n);
		printf("\n");	
	}

	return 0;
}

#include <stdio.h>

int nativeOnenum(int n)
{
	int count = 0;

	while (n) {
		if (n & 1)	count ++;
		n >>= 1;
	}

	return count;
}

int oneNum(int n)
{
	int count, flag;

	for (count = 0, flag = 1; flag; flag <<= 1) {
		if (flag & n)	count ++;
	}

	return count;
}

int quickOne(int n)
{
	int count = 0;

	while (n) {
		count ++;
		n = n & (n - 1);
	}

	return count;
}


int main(void)
{
	int n;

	while (scanf("%d", &n) != EOF) {
		// printf("%d\n", nativeOnenum(n));

		printf("%d\n", oneNum(n));

		printf("%d\n", quickOne(n));
	}

	return 0;
}

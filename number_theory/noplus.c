#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int m, n, result, carry, tmp;

	while (scanf("%d %d", &m, &n) != EOF) {
		carry = (m & n) << 1;
		result = m ^ n;

		while (carry != 0) {
			tmp = carry;
			carry = (carry & result) << 1;
			result ^= tmp;
		}
	
		printf("%d\n", result);
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 20123

int calculate(char *str, int stand)
{
	int i, len, cur, low, high, pos, factor = 1, count = 0;

	len = strlen(str);
	pos = len - 1;

	while (pos >= 0) {
		cur = str[pos] - '0';
		
		for (low = 0, i = pos + 1; i < len; i ++) {
			low = ((10 * low) % MOD + str[i] - '0') % MOD;
		}

		for (high = 0, i = 0; i < pos; i ++) {
			high = ((10 * high) % MOD + str[i] - '0') % MOD;
		}

		if (cur < stand) {
			count += (high * factor) % MOD;
		} else if (cur == stand) {
			count += (high * factor + low + 1) % MOD;
		} else {
			count += ((high + 1) * factor) % MOD;
		}

		factor = (factor * 10) % MOD;
		pos --;
	}

	return count;
}

int main(void)
{
	int one, two;
	char str[1000];

	while (scanf("%s", str) != EOF) {
		one = calculate(str, 1);
		two = calculate(str, 2);

		printf("%d\n", (one + two) % MOD);
	}

	return 0;
}

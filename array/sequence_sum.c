#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int st, ed, s, flag, sum, i;

	while (scanf("%d", &s) != EOF && s >= 0) {
		for (st = 1, ed = 2, sum = 3, flag = 0; st * 2 < s + 1;) {
			if (sum == s) {
				flag = 1;
				for (i = st; i <= ed; i ++) {
					if (i == ed) {
						printf("%d\n", ed);
					} else {
						printf("%d ", i);
					}
				}
				ed += 1;
				sum += ed;
			} else if (sum < s) {
				ed += 1;
				sum += ed;
			} else {
				sum -= st;
				st += 1;
			}

		}

		if (flag == 0) {
			printf("Pity!\n");
		}

		printf("#\n");
	}

	return 0;
}

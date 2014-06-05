#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, i, tmp, flag;

	while (scanf("%d", &n) != EOF && n != 0) {
		flag = 0;
		for (i = 2; i * i <= n; i ++) {
			tmp = i * i;
			if (n % tmp == 0) {
				flag = 1;
				break;
			}
		}

		if (flag == 1) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}	

	return 0;
}

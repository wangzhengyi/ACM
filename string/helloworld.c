#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[1001];
	int i, j, n1, n2, len, max;

	while (scanf("%s", str) != EOF) {
		len = strlen(str);
		
		// 穷举法
		for (n1 = max = 3; 2 * n1 <= len + 2; n1 ++) {
			for (n2 = n1; n2 <= len - 4; n2 ++) {
				if (2 * n1 + n2 == len  + 2) {
					if (max < n1)
						max = n1;
				}
			}
		}

		n1 = max;
		n2 = len + 2 - 2 * n1;

		for (i = 0; i < n1; i ++) {
			if (i == n1 - 1) {
				for (j = 0; j < n2; j ++) {
					printf("%c", str[i + j]);
				}
				printf("\n");
			} else {
				printf("%c", str[i]);
				for (j = 1; j < n2 - 1; j ++)
					printf(" ");
				printf("%c\n", str[len - 1 - i]);
			}
		}
	}

	return 0;
}

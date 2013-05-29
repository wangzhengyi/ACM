#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[26];

int main()
{
	int i, n, d, flag;
	char str[10001];

	while (scanf("%s", str) != EOF) {
		memset(arr, 0, sizeof(arr));
		for (i = 0, n = strlen(str); i < n; i ++) {
			d = str[i] - 'A';
			arr[d] += 1;
		}

		for (i = 0, flag = 0; i < n; i ++) {
			d = str[i] - 'A';
			if (arr[d] == 1) {
				flag = 1;
				break;
			}
		}

		if (flag)
			printf("%d\n", i);
		else
			printf("-1\n");
	}

	return 0;
}

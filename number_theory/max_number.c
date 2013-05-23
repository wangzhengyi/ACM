#include <stdio.h>

int main()
{
	int i, n, max, a[11000];

	while (scanf("%d", &n) != EOF) {
		scanf("%d", &max);
		
		for (i = 1; i < n; i ++) {
			scanf("%d", &a[i]);
			if (max < a[i]) {
				max = a[i];
			}
		}

		printf("%d\n", max);
	}

	return 0;
}

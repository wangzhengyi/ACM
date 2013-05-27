#include <stdio.h>
#include <stdlib.h>

#define LEN 100005

int main()
{
	long long int i, n, time, element, *arr;
	int flag;

	while (scanf("%lld", &n) != EOF) {
		arr = (long long int *)malloc(sizeof(long long int) * n);

		for (i = 0; i < n; i ++)
			scanf("%lld", arr + i);

		for (i = 1, time = 1, element = arr[0]; i < n; i ++) {
			if (time == 0) {
				element = arr[i];
				time = 1;
				continue;
			}	
			if (element == arr[i]) {
				time ++;
			} else {
				time --;
			}
		}

		for (i = time = 0; i < n; i ++) {
			if (element == arr[i])
				time ++;
		}
		
		flag = (time * 2 > n) ? 1 : 0;

		if (flag) {
			printf("%lld\n", element);
		} else {
			printf("-1\n");
		}
	}

	return 0;
}

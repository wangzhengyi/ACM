#include <stdio.h>
#include <stdlib.h>

int firstone_loc(int num)
{
	int i;
	for (i = 0; (num & 1) == 0; i ++) {
		num = num >> 1;
	}

	return i;
}

int judge_loc(int num, int loc)
{
	num = num >> loc;
	
	return (num & 1);
}

int main(void)
{
	int i, n, unique, first, second, loc, flag, *arr;

	while (scanf("%d", &n) != EOF) {
		arr = (int *)malloc(sizeof(int) * n);
		for (i = unique = 0; i < n; i ++) {
			scanf("%d", arr + i);
			unique ^= arr[i]; 
		}

		// 第一个为1的位
		loc = firstone_loc(unique);

		for (i = first = second = 0; i < n; i ++) {
			flag = judge_loc(arr[i], loc);
			if (flag) {
				first ^= arr[i];
			} else {
				second ^= arr[i];
			}
		}

		if (first < second) {
			printf("%d %d\n", first, second);
		} else {
			printf("%d %d\n", second, first);
		}

		free(arr);
	}

	return 0;
}

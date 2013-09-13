#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100005

typedef long long int lld;

lld a[N], b[N];


int compare(const void *p, const void *q)
{
	const lld *a = p;
	const lld *b = q;

	return *a - *b;
}

lld countNum(lld n, lld m, lld mid)
{
	lld i, j, count;
	for (i = 0, count = 0; i < n; i ++) {
		for (j = m; j >= 0 && a[i] + b[j] > mid; j --) {
			count ++;
		}
	}

	return count;
}


lld binarySearch(lld n, lld m, lld k)
{
	lld low, high, mid, num;

	low = a[0] + b[0];
	
	high = a[n - 1] + b[m - 1];

	while (low <= high) {
		mid = (low + high) >> 1;
		
		num = countNum(n, m, mid);
		if (num == k) {
			return mid;
		} else if (num > k) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}	
	
	return -1;
}


int main(void)
{
	lld i, j, n, m, k, ret;

	while (scanf("%lld %lld %lld", &n, &m, &k) != EOF) {
		for (i = 0; i < n; i ++)
			scanf("%lld", a + i);

		for (j = 0; j < m; j ++)
			scanf("%lld", b + j);

		
		qsort(a, n, sizeof(a[0]), compare);

		qsort(b, m, sizeof(b[0]), compare);

		
		ret = binarySearch(n, m, k);
		
		printf("%lld\n", ret);
	}

	return 0;
}

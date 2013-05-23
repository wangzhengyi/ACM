#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int page[505], sum, min, ans;
int visit[505];
int m, k;

int divide_process(long long mid)
{
	int cnt, pos, flag;
	long long int total;
	cnt = 0;
	pos = m - 1;
	memset(visit, 0, sizeof(visit));

	while (pos >= 0) {
		total = 0;
		flag = 1;

		while (pos >= 0 && total + page[pos] <= mid) {
			flag = 0;
			total += page[pos];
			-- pos;
		}

		if (flag)
			return k + 1;
		if (pos >= 0)
			visit[pos] = 1;
		++ cnt;
	}
	return cnt;
}


long long binary_search()
{
	long long left, right, middle;
	left = min;
	right = sum;

	while (left < right) {
		middle = (left + right) >> 1;
		if (divide_process(middle) <= k)
			right = middle;
		else
			left = middle + 1;
	}

	return right;
}

void result_process()
{
	int i, cnt;
	long long int num, max;
	cnt	= divide_process(ans);

	for (i = 0; i < m - 1 && cnt < k; i ++) {
		if (!visit[i]) {
			visit[i] = 1;
			++cnt;
		}
	}

	for (i = 0, num = max = 0; i < m; i ++) {
		num += page[i];
		if (visit[i]) {
			if (num > max)
				max = num;
			num = 0;
		}
	}

	if (num > max)
		max = num;
	printf("%lld\n", max);

}

int main()
{
	int i, n;

	scanf("%d", &n);

	while (n --) {
		scanf("%d %d", &m, &k);
		sum = min = 0;

		for (i = 0; i < m; i ++) {
			scanf("%lld", &page[i]);
			sum += page[i];
			if (page[i] > min)
				min = page[i];
		}

		ans = binary_search();
		result_process();
	}

	return 0;
}

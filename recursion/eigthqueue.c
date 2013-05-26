#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EIGHT 8

struct result
{
	int total;
	int num[10];
};

int wzyindex, column[10];
struct result results[100];

/**
 * Description:预处理八皇后的下标数组
 */
void pre_prosess(int n)
{
	int i;

	for (i = 1; i <= n; i ++) {
		column[i] = i;
	}
}

/**
 * Description:column数组数字交换
 */
void swap(int begin, int k)
{
	int temp;

	temp = column[begin];
	column[begin] = column[k];
	column[k] = temp;
}

/**
 * Description:防止全排列出现重复数据
 */
int check_swap(int begin, int k)
{
	int i;
	for (i = begin; i < k; i ++) {
		if (column[i] == column[k]) {
			return 0;
		}
	}
	return 1;
}

int is_eightqueue(int n)
{
	int i, j;
	for (i = 1; i <= n; i ++) {
		for (j = i + 1; j <= n; j ++) {
			if (i - j == column[i] - column[j] || i - j == column[j] - column[i])
				return 0;
		}
	}
	return 1;
}

void permutation_queue(int begin, int end)
{
	int k, total;
	if (begin == end) {	// 检查八皇后排列正确性
		if (is_eightqueue(end)) {
			for (k = 1, total = 0; k <= end; k ++) {
				total = 10 * total + column[k];
				results[wzyindex].num[k] = column[k]; 
			}
			results[wzyindex].total = total;
			wzyindex ++;
		}
	} else {	// 全排列
		for (k = begin; k <= end; k ++) {
			if (check_swap(begin, k)) { // 保证无重复的全排列
				swap(begin, k);
				permutation_queue(begin + 1, end);
				swap(begin, k);
			}	
		}
	}
}

int compare(const void *p, const void *q)
{
	const struct result *a = p;
	const struct result *b = q;

	return a->total - b->total;
}

int main()
{
	int i, n, m;
	pre_prosess(EIGHT);
	wzyindex = 0;
	permutation_queue(1, EIGHT);
	qsort(results, wzyindex, sizeof(results[0]), compare);
	while (scanf("%d", &n) != EOF) {
		while (n --) {
			scanf("%d", &m);
			m -= 1;
			for (i = 1; i <= EIGHT; i ++) {
				printf("%d", results[m].num[i]);
			}
			printf("\n");
		}
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int column[14];
int count;

void pre_process();
void swap_process(int a, int b);
int check_queue(int n);
void permutation_process(int i, int n);

int main()
{
	int n;

	while (scanf("%d", &n) != EOF) {
		pre_process();
		count = 0;
		permutation_process(1, n);
		printf("%d\n", count);
	}

	return 0;
}

void pre_process()
{
	int i;

	for (i = 0; i <= 13; i ++) {
		column[i] = i;
	}
}

void swap_process(int a, int b)
{
	int temp;
	temp = column[a];
	column[a] = column[b];
	column[b] = temp;
}

int check_queue(int n)
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

int is_swap(int begin, int k)
{
	int i;
	for (i = begin; i < k; i ++) {
		if (column[i] == column[k])
			return 0;
	}
	return 1;
}

void permutation_process(int i, int n)
{
	int k, flag;
	if (i == n) {
		flag = check_queue(n);
		if (flag) 
			count ++;
	}else {
		for (k = i; k <= n; k ++) {
			if (is_swap(i, k)) {
				swap_process(k, i);
				permutation_process(i + 1, n);
				swap_process(k, i);
			}
		}
	}
}

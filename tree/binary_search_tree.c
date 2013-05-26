#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

int judge_bst(int *arr, int len);

int main()
{
	int i, n, flag, arr[100001];

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i ++)
			scanf("%d", &arr[i]);
		
		flag = judge_bst(arr, n);
		(flag == 1) ? printf("Yes\n") : printf("No\n");
	}

	return 0;
}

int judge_bst(int *arr, int len)
{
	int i, j, root;
	
	// 递归终止条件
	if (len <= 0)
		return true;

	root = *(arr + len - 1);

	// 区分左子树
	for (i = 0; i < len - 1; i ++) {
		if (*(arr + i) > root)
			break;
	}

	// 查找右子树是否符合要求
	for (j = i; j < len - 1; j ++) {
		if (*(arr + j) < root) 
			return false;
	}

	// 递归的判断左右子树是否符合要求
	int left, right;
	left = true;
	left = judge_bst(arr, i);

	right = true;
	right = judge_bst(arr + i, len - 1 - i);

	return (right && left);
}

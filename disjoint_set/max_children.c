#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 200 	// 假设最大测试200个数据

int main(void)
{
	int i, j, data, min, max, begin, seq, count, initial[N], *arr;

	// 最大元素赋初值，假设数据均为正整数
	max = 0;
	for (i = 0; scanf("%d", &data) != EOF; i ++) {
		if (i == 0) 
			min = data;
		if (data > max)
			max = data;
		else if (data < min)
			min =  data;
		initial[i] = data;
	}

	// 利用hash的思想，动态申请一个(max+1)大小的数组
	arr = (int *)malloc(sizeof(int) * (max + 1));
	memset(arr, 0, sizeof(arr));
	for (j = 0; j < i; j ++)
		arr[initial[j]] = 1;

	// 查找最长连续1的数目
	for (i = begin = min, seq = 0; i <= max;) {
		if (arr[i]) {
			for (j = i + 1, count = 1; j <= max; j ++) {
				if (arr[j]) {
					count ++;
				} else {
					break;
				}
			}
			// 判断是否需要更新最多连续数的大小
			if (count > seq) {
				seq = count;
				begin = i;
			}
			
			// 更新index
			i = j;
		} else {
			i ++;
		}
	}

	// 打印输出
	printf("%d:", seq);
	for (i = begin, j = 0; j < seq; j ++, i ++) {
		if (j == 0) {
			printf("[%d,", i);
		} else if (j == seq - 1){
			printf("%d]\n", i);
		} else {
			printf("%d,", i);
		}
	}

	return 0;
}

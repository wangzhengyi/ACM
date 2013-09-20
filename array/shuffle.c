#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int arr[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void shuffleArray()
{
	int i, loc, tmp;
	time_t t;

	srand((unsigned int)time(&t));
	
	// 洗牌算法
	for (i = 0; i < N; i ++) {
		loc = rand() % (i + 1);
		tmp = arr[loc];
		arr[loc] = arr[i];
		arr[i] = tmp;
	}

	// 打印输出
	for (i = 0; i < N; i ++)
		printf("%d ", arr[i]);
	printf("\n");
}


int main(void)
{
	int i, n;

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i ++) {
			// 测试洗牌
			shuffleArray();
		}
	}

	return 0;
}

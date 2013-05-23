#include <stdio.h>
#include <stdlib.h>

long long int pay[10005];

struct task
{
	int begin, end, value;
};

long long int relative_max(int i, struct task *t)
{
	int j = 0;

	while (t[j].end <= t[i].begin) {
		j ++;
	}
	// 找到最近的一个截至时间小于指定时间的项目
	j -= 1;
	return pay[j] + t[i].value;
}

int main()
{
	int i, n;
	long long int cost1, cost2;
	struct task tasks[10005];

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i ++) {
			scanf("%d %d %d", &tasks[i].begin, &tasks[i].end, &tasks[i].value);
		}
	
		// 典型的动态规划
		// 最优子问题解为：max(cost[i - 1], task[i].value + 结束时间小于task[i].end的最大值)
		pay[0] = tasks[0].value;
		for (i = 1; i < n; i ++) {
			cost1 = pay[i - 1];
			cost2 = relative_max(i, tasks);
			pay[i] = (cost1 >= cost2) ? cost1 : cost2;
		}

		printf("%lld\n", pay[n - 1]);
	}

	return 0;
}

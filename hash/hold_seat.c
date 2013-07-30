#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct people {
	int begin;
	int count;
} people;

int arrangeSeat(int id, int seq, int total, int *hash, people *ps)
{
	int i, j, k, flag, begin;

	flag = 0;
	for (i = 0; i <= total - seq;) {
		flag = 0;
		if (hash[i] == -1) {
			for (j = i, k = 0; j < total && k < seq; j ++, k ++) {
				if (hash[j] != -1)
					break;
			}

			if (k == seq) { // 分配成功
				begin = i;
				for (; i < j; i ++)
					hash[i] = id;
				flag = 1;
				break;
			} else {
				i = j;
			}
		} else {
			i ++;
		}
	}

	if (flag) {
		ps[id].begin = begin;
		ps[id].count = seq;
	}

	return flag;
}

int main(void)
{
	int i, n, m, k, id, seq, total, *seat;
	people *ps;
	char cmd[4];

	while (scanf("%d %d", &n, &m) != EOF) {
		total = n * n;
		seat = (int *)malloc(sizeof(int) * total);
		for (i = 0; i < total; i ++)
			seat[i] = -1;
	
		ps = (people *)malloc(sizeof(people) * (m + 1));
		for (i = 0; i <= m; i ++) {
			ps[i].begin = -1;
			ps[i].count = 0;
		}


		scanf("%d", &k);

		while (k --) {
			scanf("%s %d", cmd, &id);

			switch (cmd[0]) {
				case 'i' :
					scanf("%d", &seq);
					if (ps[id].count > 0) {	// 之前占座没有释放
						printf("no\n");
					} else if (seq > total) {
						printf("no\n");
					} else {
						if (arrangeSeat(id, seq, total, seat, ps)) {
							printf("yes\n");
						} else {
							printf("no\n");
						}
					}
					break;
				case 'o' :
					if (ps[id].count > 0) {
						for (i = ps[id].begin; i < ps[id].begin + ps[id].count; i ++)
							seat[i] = -1;
						ps[id].begin = -1;
						ps[id].count = 0;
					}
					break;
			}
		}

		free(seat);
		free(ps);
	}

	return 0;
}

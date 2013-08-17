#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 7
#define N 40005

typedef struct application {
	int ge, gi, gf, loc, id;
	int choice[M];
} application;

typedef struct school {
	int quota;
	int count;
	application people[N];
} school;

int compare(const void *p, const void *q)
{
	const application *a = p;
	const application *b = q;

	if (a->gf > b->gf) {
		return -1;
	} else if (a->gf < b->gf) {
		return 1;
	} else {
		return b->ge - a->ge;
	}
}

int compare_id(const void *p, const void *q)
{
	const application *a = p;
	const application *b = q;

	return a->id - b->id;
}

int main(void)
{
	int i, j, n, m, k, choice;
	application *apply;
	school *schools;

	while (scanf("%d %d %d", &n, &m, &k) != EOF) {
		apply = (application *)malloc(sizeof(application) * n);	
		schools = (school *)malloc(sizeof(school) * m); 

		// 学校的配额
		for (i = 0; i < m; i ++) {
			scanf("%d", &schools[i].quota);	
			schools[i].count = 0;
		}

		// 构造数据
		for (i = 0; i < n; i ++) {
			scanf("%d %d", &apply[i].ge, &apply[i].gi);
			apply[i].gf = apply[i].ge + apply[i].gi;
			for (j = 0; j < k; j ++) {
				scanf("%d", &choice);
				apply[i].choice[j] = choice;
			}
			apply[i].id = i;
		}

		// 边界条件
		if (m == 0 || n == 0 || k == 0) {
			printf("\n");
			continue;
		}

		// 排序
		qsort(apply, n, sizeof(apply[0]), compare);
		apply[0].loc = 0;
		for (i = 1; i < n; i ++) {
			if (apply[i].gf == apply[i - 1].gf && apply[i].ge == apply[i - 1].ge) {
				apply[i].loc = apply[i - 1].loc;
			} else {
				apply[i].loc = apply[i - 1].loc + 1;
			}
		}

		// 学校选择
		for (i = 0; i < n; i ++) {
			for (j = 0; j < k; j ++) {
				choice = apply[i].choice[j];
				if (schools[choice].quota > 0) {
					schools[choice].people[schools[choice].count ++] = apply[i];
					schools[choice].quota --;
					break;
				} else {
					if (schools[choice].count > 0 && apply[i].loc == schools[choice].people[schools[choice].count - 1].loc) {
						schools[choice].people[schools[choice].count ++] = apply[i];
						schools[choice].quota --;
						break;
					}
				}
			}
		}

		for (i = 0; i < m; i ++) {
			if (schools[i].count > 0) {
				qsort(schools[i].people, schools[i].count, sizeof(schools[i].people[0]), compare_id);
				for (j = 0; j < schools[i].count; j ++) {
					if (j == schools[i].count - 1)
						printf("%d\n", schools[i].people[j].id);
					else
						printf("%d ", schools[i].people[j].id);	
				}
			} else {
				printf("\n");
			}	
		}

		free(apply);
		free(schools);	
	}

	return 0;	
}

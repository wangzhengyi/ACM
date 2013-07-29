#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct monkey {
	char name[101];
	int strong;
	int eat;
} monkey;

int compare(const void *p, const void *q)
{
	const monkey *a = p;
	const monkey *b = q;

	if (a->strong != b->strong) {
		return b->strong - a->strong;
	} else {
		return strcmp(a->name, b->name);
	}
}



int main(void)
{
	int i, j, n, m, total;
	monkey *msets;
	char name[101];

	while (scanf("%d %d", &n, &m) != EOF) {
		msets = (monkey *)malloc(sizeof(monkey) * n);
		for (i = 0; i < n; i ++) {
			scanf("%s %d %d", msets[i].name, &msets[i].strong, &msets[i].eat);
		}

		qsort(msets, n, sizeof(msets[0]), compare);

		for (i = 0; i < m; i ++) {
			scanf("%s", name);
			for (j = 0, total = 1; j < n; j ++) {
				if (strcmp(msets[j].name, name) != 0) {
					total += msets[j].eat;
				} else {
					break;
				}
			}		
			printf("%d\n", total);
		}


		free(msets);
	}

	return 0;
}

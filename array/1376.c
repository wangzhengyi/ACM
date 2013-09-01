#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct pr {
	int rs, index;
} pr;

int compare(const void *p, const void *q)
{
	const pr *a = p;
	const pr *b = q;

	return a->rs - b->rs;
}

int main(void)
{
	int i, n, min, tmp, data;
	pr *p;

	while (scanf("%d", &n) != EOF) {
		p = (pr *)malloc(sizeof(pr) * n);
	
		scanf("%d", &p[0].rs);
		p[0].index = 0;
		min = p[0].rs;

		for (i = 1; i < n; i ++) {
			scanf("%d", &data);
			p[i].rs = p[i - 1].rs + data;
			p[i].index = i;

			if (abs(p[i].rs) < abs(min))
				min = p[i].rs;
		}


		qsort(p, n, sizeof(p[0]), compare);

		for (i = 1; i < n; i ++) {		
			if (p[i].index > p[i - 1].index) {
				tmp = p[i].rs - p[i - 1].rs;
			} else {
				tmp = p[i - 1].rs - p[i].rs;
			}

			if (abs(tmp) < abs(min)) {
				min = tmp;
			} else if (abs(tmp) == abs(min) && tmp > min) {
				min = tmp;
			}
		}

		printf("%d\n", min);

		free(p);
	}


	return 0;
}

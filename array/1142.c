#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21620

int physical[MAX], emotional[MAX], mental[MAX];

int main(void)
{
	int i, j, p, e, m, d, count = 1;

	while (scanf("%d %d %d %d", &p, &e, &m, &d) != EOF) {
		if (p == -1 && e == -1 && m == -1 && d == -1)	break;

		for (i = 0; i < MAX; i ++) {
			physical[i] = emotional[i] = mental[i] = 0;
		}

		for (i = p; i < MAX; i += 23) {
			physical[i] = 1;
		}

		for (i = e; i < MAX; i += 28) {
			emotional[i] = 1;
		}

		for (i = m; i < MAX; i += 33) {
			mental[i] = 1;
		}

		for (i = d + 1, j = 1; i < MAX; i ++) {
			if (physical[i] && emotional[i] && mental[i]) {
				break;
			} else {
				j ++;
			}
		}

		printf("Case %d: the next triple peak occurs in %d days.\n", count ++, j);
	}


	return 0;
}

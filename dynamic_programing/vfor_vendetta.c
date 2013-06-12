#include <stdio.h>
#include <stdlib.h>

struct explosive
{
	int weight, power;
};

int cmpstruct(const void *p, const void *q)
{
	const struct explosive *a = p;
	const struct explosive *b = q;

	return a->weight - b->weight;
}

void max_power(struct explosive *explosives, int c, int s)
{
	int i, j, loc, p, num[102][1002];

	for (i = 0; i <= c; i ++)
		num[i][0] = 0;

	for (i = 0; i <= s; i ++)
		num[0][i] = 0;

	for (i = 1; i <= c; i ++) {
		for (j = 1; j <= s; j ++) {
			if (explosives[i].weight > j) {
				num[i][j] = num[i - 1][j];
			} else {
				loc = j - explosives[i].weight;
				p = explosives[i].power + num[i - 1][loc];
				num[i][j] = num[i - 1][j] > p ? num[i - 1][j] : p; 
			}
		}
	}

	printf("%d\n", num[c][s]);
}


int main(void)
{
	int i, s, c;
	struct explosive *explosives;

	while (scanf("%d %d", &s, &c) != EOF) {
		explosives = (struct explosive *)malloc(sizeof(struct explosive) * (c + 1));
		for (i = 1; i <= c; i ++)
			scanf("%d %d", &explosives[i].weight, &explosives[i].power);
		explosives[0].weight = explosives[0].power = 0;

		qsort(explosives, c, sizeof(explosives[0]), cmpstruct);
		
		if (s < explosives[1].weight) {
			printf("0\n");
		} else {
			max_power(explosives, c, s);
		}

		free(explosives);
	}
	return 0;
}

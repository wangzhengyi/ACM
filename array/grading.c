#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int p, t, g1, g2, g3, gj;
	double grade;

	while (scanf("%d %d %d %d %d %d", &p, &t, &g1, &g2, &g3, &gj) != EOF) {
		if (abs(g1 - g2) <= t) {
			grade = (double)(g1 + g2) / 2.0;
		} else {
			if (abs(g1 - g3) <= t && abs(g2 - g3) > t) {
				grade = (double)(g1 + g3) / 2.0;
			} else if (abs(g2 - g3) <= t && abs(g1 - g3) > t) {
				grade = (double)(g2 + g3) / 2.0;
			} else if (abs(g1 - g3) <= t && abs(g2 - g3) <= t) {
				grade = (double)(g1 + g2 + g3) / 3.0;
			} else {
				grade = (double)(gj * 1.0);
			}
		}

		printf("%.1lf\n", grade);	
	}

	return 0;
}

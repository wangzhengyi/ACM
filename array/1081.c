#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int lint;

#define N 10000

lint matrix[2][2], middle[2][2];

void multiMatrix(lint a[2][2], lint b[2][2], lint c[2][2])
{
	lint i, j, d[2][2];

	d[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % N;
	d[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % N;
	d[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % N;
	d[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % N;

	for (i = 0; i < 2; i ++) {
		for (j = 0; j < 2; j ++) {
			c[i][j] = d[i][j];
		}
	}
}

void middleProc(lint n)
{
	middle[0][0] = middle[1][1] = 1;
	middle[0][1] = middle[1][0] = 0;

	while (n) {
		if (n & 1) {
			multiMatrix(middle, matrix, middle);
		}
		multiMatrix(matrix, matrix, matrix);

		n >>= 1;
	}
}

int main(void)
{
	lint a0, a1, p, q, k, r;

	while (scanf("%lld %lld %lld %lld %lld", &a0, &a1, &p, &q, &k) != EOF) {
		if (k == 0) {
			printf("%lld\n", a0 % N);
			continue;
		}

		if (k == 1) {
			printf("%lld\n", a1 % N);
			continue;
		}

		matrix[0][0] = p;
		matrix[0][1] = q;
		matrix[1][0] = 1;
		matrix[1][1] = 0;

		middleProc(k - 1);	
		
		r = (middle[0][0] * a1 + middle[0][1] * a0) % N;	

		printf("%lld\n", r);
	}

	return 0;
}

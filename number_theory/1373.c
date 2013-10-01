#include <stdio.h>
#include <stdlib.h>

int calOne(int n)
{
	int low, cur, high, factor = 1, num = 0;

	while (n / factor != 0) {
		cur = (n / factor) % 10;
		low = n - (n / factor) * factor;
		high = n / (factor * 10);

		switch (cur) {
			case 0 :
				num += high * factor;
				break;
			case 1 :
				num += high * factor + low + 1;
				break;
			default :
				num += (high + 1) * factor;
				break;
		}

		factor *= 10;
	}

	return num;
}


int main(void)
{
	int a, b, num_a, num_b, tmp;

	while (scanf("%d %d", &a, &b) != EOF) {
		if (a > b) {
			tmp = a;
			a = b;
			b = tmp;
		}

		if (a > 0)	
			num_a = calOne(a - 1);
		else
			num_a = 0;

		num_b = calOne(b);

		if (num_b >= num_a)
			printf("%d\n", num_b - num_a);
		else
			printf("0\n");
	}
	
	return 0;
}

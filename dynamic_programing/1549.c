#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculate_num(int p) {
	int money[7] = {1, 2, 5, 10, 20, 50, 100};
	int i, tmp, num = 0;

	for (i = 6; i >= 0; i --) {
		if (p >= money[i]) {
			tmp = p / money[i];
			p = p % (tmp * money[i]);
			num += tmp;
		}
	}

	return num;
}


int main(void) {
	int p, res;

	while (scanf("%d", &p) != EOF) {
		res = calculate_num(p);
		printf("%d\n", res);	
	}

	return 0;
}

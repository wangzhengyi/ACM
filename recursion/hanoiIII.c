#include <stdio.h>
#include <stdlib.h>

long int count;

void send(char src, char dst, int num)
{
	printf("Move %d disk from %c to %c!\n", num, src, dst);
	count += 1;
}


void move(char src, char dst, int n)
{
	if (n == 1) {
		send(src, 'B', n);
		send('B', dst, n);
	} else {
		move(src, dst, n - 1);
		send(src, 'B', n);
		move(dst, src, n - 1);
		send('B', dst, n);
		move(src, dst, n - 1);
	}
}


int main(void)
{
	int n;

	while (scanf("%d", &n) != EOF) {
		count = 0;
		move('A', 'C', n);
		printf("%ld\n", count);
	}

	return 0;
}

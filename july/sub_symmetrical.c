#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * 最长回文字串的长度
 */
void maxSymmetricalSubstring(char *str, int n)
{
	int maxlength, len;
	char *pre, *next, *current;

	current = str + 1;
	maxlength = 0;

	while (current < (str + n) && *current != '\0') {
		pre = current - 1;
		next = current + 1;

		while (pre >= str && next < (str + n) && *pre == *next) {
			pre --;
			next ++;	
		}

		len = (next - 1) - (pre + 1) + 1;
		
		if (len > maxlength) {
			maxlength = len;
		}

		pre = current - 1;
		next = current;

		while (pre >= str && next < (str + n) && *pre == *next) {
			pre --;
			next ++;
		}
		len = (next - 1) - (pre + 1) + 1;

		if (len > maxlength) {
			maxlength = len;
		}

		current ++;
	}
	
	printf("%d\n", maxlength);
}	

int main(void)
{
	char str[200001];
	int n;

	while (scanf("%s", str) != EOF) {
		n = strlen(str);
		if (n == 1)
			printf("1\n");
		else
			maxSymmetricalSubstring(str, n);
	}

	return 0;
}

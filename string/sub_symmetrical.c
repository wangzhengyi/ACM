#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * 最长回文字串的长度
 */
void maxSymmetricalSubstring(char *str)
{
	int maxlength, len;
	char *pre, *next, *current;
	
	current = str + 1;
	maxlength = 0;

	while (*current != '\0') {
		pre = current - 1;
		next = current + 1;

		while (pre >= str && *next != '\0' && *pre == *next) {
			pre --;
			next ++;	
		}

		len = (next - 1) - (pre + 1) + 1;
		
		if (len > maxlength) {
			maxlength = len;
		}

		pre = current - 1;
		next = current;

		while (pre >= str && *next != '\0' && *pre == *next) {
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
	char str[101];

	while (gets(str)) {
		maxSymmetricalSubstring(str);
	}

	return 0;
}

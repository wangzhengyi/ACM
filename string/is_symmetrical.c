#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void isSymmetrical(char *str)
{
	char *begin, *end;
	int flag, len = strlen(str);

	for (begin = str, end = str + len - 1, flag = 1; begin <= end; begin ++, end --) {
		if (*begin != *end) {
			flag = 0;
			break;
		}
	}

	if (flag)
		printf("Yes!\n");
	else
		printf("No!\n");
}


int main(void)
{
	char str[1001];

	while (gets(str)) {
		isSymmetrical(str);
	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LEN 16

typedef unsigned int uint;

uint ipTint(char *ipstr)
{
	if (ipstr == NULL)	return 0;

	char *token;
	uint i = 3, total = 0, cur;

	token = strtok(ipstr, ".");

	while (token != NULL) {
		cur = atoi(token);
		if (cur >= 0 && cur <= 255) {
			total += cur * pow(256, i);
		}
		i --;
		token = strtok(NULL, ".");
	}

	return total;
}

void swapStr(char *str, int begin, int end)
{
	int i, j;

	for (i = begin, j = end; i <= j; i ++, j --) {
		if (str[i] != str[j]) {
			str[i] = str[i] ^ str[j];
			str[j] = str[i] ^ str[j];
			str[i] = str[i] ^ str[j];
		}
	}
}

char* ipTstr(uint ipint)
{
	char *new = (char *)malloc(LEN);
	memset(new, '\0', LEN);
	new[0] = '.';
	char token[4];
	int bt, ed, len, cur;

	while (ipint) {
		cur = ipint % 256;
		sprintf(token, "%d", cur);
		strcat(new, token);
		ipint /= 256;
		if (ipint)	strcat(new, ".");
	}

	len = strlen(new);
	swapStr(new, 0, len - 1);

	for (bt = ed = 0; ed < len;) {
		while (ed < len && new[ed] != '.') {
			ed ++;
		}
		swapStr(new, bt, ed - 1);
		ed += 1;
		bt = ed;
	}

	new[len - 1] = '\0';

	return new;
}

int main(void)
{
	char ipstr[LEN], *new;
	uint ipint;

	while (scanf("%s", ipstr) != EOF) {
		ipint = ipTint(ipstr);
		printf("%u\n", ipint);

		new = ipTstr(ipint);
		printf("%s\n", new);
	}

	return 0;
}


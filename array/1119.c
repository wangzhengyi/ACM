#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1005

typedef struct bigdata {
	char str[N];
	int len;
} bigdata;

int reverseData(bigdata *d)
{
	int i, j, len;
	char tmp;
	len = strlen(d->str);

	for (i = 0, j = len - 1; i <= j; i ++, j --) {
		tmp = d->str[i];
		d->str[i] = d->str[j];
		d->str[j] = tmp;
	}

	for (i = len - 1; i >= 0; i --) {
		if (d->str[i] != '0')
			break;
	}
	
	d->str[i + 1] = '\0'; 
	return i + 1;
}

void addBigData(bigdata first, bigdata *result)
{
	int i, len1, len2, len, c;
	char tmp;

	bigdata new;
	

	len1 = first.len;
	len2 = result->len;
	len = (len1 > len2) ? len2 : len1;

	for (i = 0; i < len; i ++) {
		tmp = (first.str[i] - '0' + result->str[i] - '0' + c) % 10 + '0';
		c = (first.str[i] - '0' + result->str[i] - '0' + c) / 10;
		new.str[i] = tmp;
	}

	while (i < len1) {
		tmp = (first.str[i] - '0' + c) % 10 + '0';
		c = (first.str[i] - '0' + c) / 10;
		new.str[i] = tmp;
		i ++;
	}

	while (i < len2) {
		tmp = (result->str[i] - '0' + c) % 10 + '0';
		c = (result->str[i] - '0' + c) / 10;
		new.str[i] = tmp;
		i ++;
	}

	while (c > 0) {
		tmp = c % 10 + '0';
		c /= 10;
		new.str[i ++] = tmp;
	}
	
	strcpy(result->str, new.str);
	result->len = i;
}


int main(void)
{
	char tmp;
	bigdata bds[N];
	bigdata result;
	result.len = 0;
	memset(result.str, '\0', sizeof(result.str));

	int i, j;

	for (i = 0; scanf("%s", bds[i].str); i ++) {
		if (strcmp(bds[i].str, "0") == 0) {
			break;
		} else {
			bds[i].len = reverseData(&bds[i]);
			/*打印测试
			printf("%s", bds[i].str);
			*/
			addBigData(bds[i], &result);
		}
		getchar();
	}

	for (i = 0, j = result.len - 1; i <= j; i ++, j --) {
		tmp = result.str[i];
		result.str[i] = result.str[j];
		result.str[j] = tmp;
	}

	puts(result.str);

	return 0;
}

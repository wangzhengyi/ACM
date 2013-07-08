#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sds {
	char str[100];
};

int cmp_struct(const void *p, const void *q)
{
	const struct sds *a = p;
	const struct sds *b = q;

	char str1[1000], str2[1000];
	memset(str1, '\0', sizeof(str1));
	memset(str2, '\0', sizeof(str2));

	strcpy(str1, a->str);
	strcat(str1, b->str);

	strcpy(str2, b->str);
	strcat(str2, a->str);

	return strcmp(str1, str2);
}


int main(void)
{
	int i, data, n;
	struct sds *sdshdr;

	while (scanf("%d", &n) != EOF) {
		sdshdr = (struct sds *)malloc(sizeof(struct sds) * n);
		for (i = 0; i < n; i ++) {
			scanf("%d", &data);
			sprintf(sdshdr[i].str, "%d", data);
		}

		qsort(sdshdr, n, sizeof(sdshdr[0]), cmp_struct);

		for (i = 0; i < n; i ++) {
			printf("%s", sdshdr[i].str);
		}
		printf("\n");

		free(sdshdr);
	}

	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define N 8

typedef struct point {
	int x, y;
} point;
point pts[N];

typedef struct string {
	char str[N + 1];
} string;
string strs[93];

int windex, count;

int isOk(int x, int y)
{
	int i, flag = 1;

	for (i = 0; i < count; i ++) {
		if (pts[i].y == y || abs(y - pts[i].y) == abs(x - pts[i].x)) {
			flag = 0;
			break;
		}
	}

	return flag;
}

void bfsEight(int level)
{
	int i;

	if (level > N) {
		for (i = 0; i < N; i ++) {
			strs[windex].str[i] = pts[i].y + '0';
		}
		strs[windex].str[i] = '\0';
		windex ++;
	} else {
		point t;
		for (i = 1; i <= N; i ++) {
			t.x = level;
			t.y = i;

			if (isOk(t.x, t.y)) {
				pts[count ++] = t;
				bfsEight(level + 1);
				count -= 1;
			}
		}
	}
}

int cmp(const void *p, const void *q)
{
	const string *a = p;
	const string *b = q;

	return strcmp(a->str, b->str);
}

int main(void)
{
	int n, num;

	count = windex = 0;

	bfsEight(1);
	qsort(strs, count, sizeof(strs[0]), cmp);

	scanf("%d", &n);

	while (n --) {
		scanf("%d", &num);

		printf("%s\n", strs[num - 1].str);
	}

	return 0;
}

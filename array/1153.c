#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 150

typedef struct point {
	char symbol;
	int pos;
} point;

typedef struct stack {
	int top;
	point data[N];
} stack;

char flag[N];

void checkLegel(char *str, int len) 
{
	stack *s = (stack *)malloc(sizeof(stack));
	s->top = 0;
	int i;
	point new;

	for (i = 0; i < len; i ++) {
		if (str[i] != '(' && str[i] != ')') {
			flag[i] = ' ';
		} else if (str[i] == '(') {
			new.pos = i;
			new.symbol = '(';
			s->data[s->top ++] = new;
		} else {
			if (s->top == 0) {
				flag[i] = '?';
			}  else {
				new = s->data[-- s->top];
				flag[new.pos] = ' ';
				flag[i] = ' ';
			}
		}
	}

	while (s->top) {
		new = s->data[-- s->top];
		flag[new.pos] = '$';
	}

	free(s);
}

int main(void)
{
	int i, len;
	char str[N];

	while (scanf("%s", str) != EOF) {
		len = strlen(str);

		checkLegel(str, len);

		puts(str);
		for (i = 0; i < len; i ++) {
			if (i == len - 1) {
				printf("%c\n", flag[i]);
			} else {
				printf("%c", flag[i]);
			}
		}
	}

	return 0;
}

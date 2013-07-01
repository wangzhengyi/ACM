#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int top;
	int data[1000005];
} stack;

typedef struct assist
{
	int top;
	int data[1000005];
} assist;

int main(void)
{
	int n, data;
	char ch[2];
	stack *s = (stack *)malloc(sizeof(stack));
	assist *a = (assist *)malloc(sizeof(assist));
	while (scanf("%d", &n) != EOF) {
		s->top = 0;
		a->top = 0;

		getchar();
		while (n --) {
			scanf("%s", ch);

			switch(ch[0]) {
				case 's' :
					scanf("%d", &data);
					if (s->top == 0) {
						a->data[a->top ++] = data;
					} else {
						a->data[a->top] = (data < a->data[a->top - 1])? data : a->data[a->top - 1];
						a->top += 1;
					}
					s->data[s->top ++] = data;
					break;
				case 'o' :
					if (s->top > 0) {
 						s->top -= 1;
						a->top -= 1;
					}
					break;
			}

			if (s->top == 0) {
				printf("NULL\n");
			} else {
				printf("%d\n", a->data[a->top - 1]);	
			}
		}
	}
	free(s);
	free(a);
	return 0;
}

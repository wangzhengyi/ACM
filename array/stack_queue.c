#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
	int top;
	int data[100005];
};

int main(void)
{
	int n, d;
	char str[20];
	struct stack *s1, *s2;

	while (scanf("%d", &n) != EOF) {
		s1 = (struct stack*)malloc(sizeof(struct stack));
		s2 = (struct stack*)malloc(sizeof(struct stack));
		s1->top = s2->top = 0;

		while (n --) {
			scanf("%s", str);
			if (strcmp(str, "PUSH") == 0) {
				scanf("%d", &d);
				s1->data[s1->top ++] = d;
			} else {
				if (s2->top > 0) {
					printf("%d\n", s2->data[s2->top - 1]);
					s2->top --;
				} else if (s1->top > 0) {
					while (s1->top > 0) {
						s2->data[s2->top ++] = s1->data[-- s1->top];
					}
					printf("%d\n", s2->data[s2->top - 1]);
					s2->top --;
				} else {
					printf("-1\n");
				}
			}
		}
	}

	return 0;
}


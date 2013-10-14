#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string {
	char str[20];
	int len;
} string;

#define MAX 10

int flag;

typedef struct trie {
	int count;
	struct trie* next[MAX];
} trie;


int cmp(const void *p, const void *q)
{
	const string *a = p;
	const string *b = q;

	return b->len - a->len;
}

void initTrie(trie **root)
{
	int i;

	*root = (trie *)malloc(sizeof(trie));
	(*root)->count = 0;

	for (i = 0; i < MAX; i ++) {
		(*root)->next[i] = NULL;
	}
}

int insertTrie(trie *root, char *str)
{
	int i, flag = 0;
	
	trie *tmp, *p = root;

	while (*str != '\0') {
		if (p->next[*str - '0'] == NULL) {
			flag = 1;
			tmp = (trie *)malloc(sizeof(trie));
			tmp->count = 1;
			for (i = 0; i < MAX; i ++) {
				tmp->next[i] = NULL;
			}
			
			p->next[*str - '0'] = tmp;
			p = tmp;
		} else {
			p = p->next[*str - '0'];
			p->count ++;
		}
		
		str ++;
	}

	return flag;
}

void delTrie(trie *root)
{
	int i;

	for (i = 0; i < MAX; i ++) {
		if (root->next[i] != NULL) {
			delTrie(root->next[i]);
		}
	}

	free(root);
}

int main(void)
{
	int t, n, i;
	string *s;
	trie *root;

	scanf("%d", &t);

	while (t --) {
		scanf("%d", &n);
		
		s = (string *)malloc(sizeof(string) * n);

		for (i = 0; i < n; i ++) {
			scanf("%s", s[i].str);
			s[i].len = strlen(s[i].str);
		}

		qsort(s, n, sizeof(s[0]), cmp);

		initTrie(&root);

		for (i = 0; i < n; i ++) {
			flag = insertTrie(root, s[i].str);
			if (flag == 0) break;
		}

		if (flag) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}

		delTrie(root);
		free(s);
	}

	return 0;
}

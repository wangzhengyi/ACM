#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 400000	// MAXN : size
int prime[MAXN];	// true : prime number


/**
 * 每行链表上的一个的节点
 */
typedef struct lnode {
	int element;
	struct lnode *next;
} *position;

/**
 * 一个点代表槽中的一个链表上的一个点
 */
typedef struct hashtb {
	int tablesize;
	position *dlist;	// 指针的指针，指向由于冲突形成的链表
} *hashtable;

/**
 * 素数筛选法
 */
void sievePrime()
{
	int i, j;

	memset(prime, 1, sizeof(prime));

	prime[0] = prime[1] = 0;

	for (i = 2; i < MAXN; i ++) {
		if (prime[i]) {
			for (j = 2 * i; j < MAXN; j += i)
				prime[j] = 0;
		}
	}
}

/**
 * 散列函数，除法散列法
 */
int hashFunction(int key, int tablesize)
{
	return key % tablesize;
}

/**
 * 找到第一个>=x的素数
 */
int nextPrime(int x)
{
	while (prime[x] == 0)
		x = x + 1;

	return x;
}

/**
 * 初始化hash表，返回指向hash表的指针
 */
hashtable initializeTable(int tablesize)
{
	if (tablesize <= 1) {
		printf("Table size is too small!\n");
		return NULL;
	}

	hashtable ht = (hashtable)malloc(sizeof(struct hashtb));
	if (ht == NULL) {
		printf("Malloc is failed!\n");
		exit(-1);
	}

	// 构建hash表的dlist指针数组
	ht->tablesize = nextPrime(tablesize);
	ht->dlist = (position *)malloc(sizeof(position) * ht->tablesize);
	if (ht->dlist == NULL) {
		printf("Malloc is failed\n");
		exit(-1);
	}

	// TODO: 这里作用没搞清楚,学习完redis的源码后回来更新
	// 初始化dlist数组
	ht->dlist[0] = (position)malloc(ht->tablesize * sizeof(struct lnode));
	if (ht->dlist[0] == NULL) {
		printf("Malloc is failed\n");
	}

	int i;
	for (i = 0; i < ht->tablesize; i ++) {
		ht->dlist[i] = ht->dlist[0] + i;
		ht->dlist[i]->next = NULL;
	}	

	return ht;
}

/**
 * 查找key所在的单元
 */
position findElement(int key, hashtable ht)
{
	position p, l;

	// 先找到所在的行
	int loc = hashFunction(key, ht->tablesize);
	l = ht->dlist[loc];
	p = l->next;

	while (p != NULL && p->element != key) {
		p = p->next;
	}

	if (p == NULL)
		return l;
	else
		return p;
}

/**
 * 向hash表中插入元素key
 */
void insertElement(int key, hashtable ht)
{
	position pos, new;
	pos = findElement(key, ht);
	
	if (pos->element != key) { // key没找到，执行插入操作
		new = (position)malloc(sizeof(struct lnode));
		if (new == NULL) {
			printf("Malloc is failed!\n");
			exit(-1);
		} else {
			new->element = key;
			new->next = pos->next;
			pos->next = new;	
		}
		printf("%d 插入表中!\n", key);
	} else {
		printf("%d 已经存在，无需重复插入!\n", key);
	}
}

/**
 * 在hash表中删除元素
 */
void deleteElement(int key, hashtable ht)
{
	position pos, new;
	pos = findElement(key, ht);

	if (pos->element == key) {
		new = ht->dlist[hashFunction(key, ht->tablesize)];
		while (new->next != pos) {
			new = new->next;
		}
		new->next = pos->next;
		free(pos);
		printf("%d删除成功!\n", key);
	} else {
		printf("%d不存在，无法删除!\n", key);
	}
}

/**
 * 查找描述
 */
inline void findDescription(position p, int key)
{
	if (p->element == key) {
		printf("%d查找成功\n", key);
	} else {
		printf("%d不在hash表中\n", key);
	}
}

int main(void)
{
	sievePrime();

	hashtable table = initializeTable(20);
	printf("hash表的大小是：%d\n", table->tablesize); // tsize = 23

	position pos = NULL;

	// 先插入6个元素
	insertElement(20, table); // --> 20
	insertElement(89, table); // --> 20
	insertElement(18, table); // --> 18
	insertElement(49, table); // --> 3
	insertElement(58, table); // --> 12
	insertElement(69, table); // --> 0

	// 测试可以查找的元素
	pos = findElement(89, table);
	findDescription(pos, 89);
	pos = findElement(20, table);
	findDescription(pos, 20);

	// 测试找不到的
	pos = findElement(25, table);
	findDescription(pos, 25);

	// 测试删除
	deleteElement(69, table);

	return 0;
}

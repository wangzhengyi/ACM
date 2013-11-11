#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct country {
    int id, rank[4];
    int gold, medal, population;
} country;
 
int cmpGold(const void *p, const void *q)
{
    const country *a = p;
    const country *b = q;
 
    return b->gold - a->gold;
}
 
int cmpMedal(const void *p, const void *q)
{
    const country *a = p;
    const country *b = q;
 
    return b->medal - a->medal;
}
 
int cmpGoldPercent(const void *p, const void *q)
{
    const country *a = p;
    const country *b = q;
 
    return b->gold * a->population - a->gold * b->population;
}
 
int cmpMedalPercent(const void *p, const void *q)
{
    const country *a = p;
    const country *b = q;
 
    return b->medal * a->population - a->medal * b->population;
}
 
int cmpId(const void *p, const void *q)
{
    const country *a = p;
    const country *b = q;
 
    return a->id - b->id;
}
 
int main(void)
{
    int n, m, i, j, type, rank, *arr;
    country *c, *d;
 
    while (scanf("%d %d", &n, &m) != EOF) {
        d = (country *)malloc(sizeof(country) * n);
        c = (country *)malloc(sizeof(country) * m);
        arr = (int *)malloc(sizeof(int) * m);
 
        for (i = 0; i < n; i ++) {
            scanf("%d %d %d", &d[i].gold, &d[i].medal, &d[i].population);
        }
 
        for (i = 0; i < m; i ++) {
            scanf("%d", &arr[i]);
            c[i] = d[arr[i]];
            c[i].id = i;
        }
 
        // 按金牌排序
        qsort(c, m, sizeof(c[0]), cmpGold);
        for (i = 0; i < m; i ++) {
            c[i].rank[0] = i;
            if (i != 0 && c[i].gold == c[i - 1].gold) {
                c[i].rank[0] = c[i - 1].rank[0];
            }
        }
 
        // 按奖牌排序
        qsort(c, m, sizeof(c[0]), cmpMedal);
        for (i = 0; i < m; i ++) {
            c[i].rank[1] = i;
            if (i != 0 && c[i].medal == c[i - 1].medal) {
                c[i].rank[1] = c[i - 1].rank[1];
            }
        }
 
        // 按金牌人口比例
        qsort(c, m, sizeof(c[0]), cmpGoldPercent);
        for (i = 0; i < m; i ++) {
            c[i].rank[2] = i;
            if (i != 0 && c[i].gold * c[i - 1].population == c[i - 1].gold * c[i].population) {
                c[i].rank[2] = c[i - 1].rank[2];
            }
        }
 
        // 按奖牌人口比例
        qsort(c, m, sizeof(c[0]), cmpMedalPercent);
        for (i = 0; i < m; i ++) {
            c[i].rank[3] = i;
            if (i != 0 && c[i].medal * c[i - 1].population == c[i - 1].medal * c[i].population) {
                c[i].rank[3] = c[i - 1].rank[3];
            }
        }
 
        // 打印输出
        qsort(c, m, sizeof(c[0]), cmpId);
        for (i = 0; i < m; i ++) {
            type = 0;
            rank = c[i].rank[0];
            for (j = 1; j < 4; j ++) {
                if (c[i].rank[j] < rank) {
                    type = j;
                    rank = c[i].rank[j];
                }
            }
            printf("%d:%d\n", rank + 1, type + 1);
        }
        printf("\n");
 
        free(c);
        free(arr);
    }
 
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000010

int judge(char *fir, char *sec)
{
	while (*fir != '\0') {
		if (*fir != *sec)	return 0;
		fir ++;
		sec ++;
	}

	return 1;
}


int main(void)
{
	int i, f1, fir;
	
	char p[N], t[N];

	while (scanf("%s %s", p, t) != EOF) {
		int lenp = strlen(p);
		int lent = strlen(t);

		i =  (lenp > lent) ? lenp - lent : 0;

		for (f1 = 0; i < lenp; i ++) {
			if (p[i] == t[0] && judge(p + i, t)) {
				fir = lenp - i;
				f1 = 1;
				break;
			}
		}

		if (f1) 
			printf("%d\n", fir);
		else
			printf("0\n");
	}

	return 0;
}

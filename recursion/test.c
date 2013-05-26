#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 8
int a[NUM+1];
char arr[92][9];
void process()
{
	int i,k,flag,not_finish=1,count=0;
	i=1;                                                
	a[1]=1;                                                
	count=0;
	while(not_finish)                
	{
		while(not_finish&&i<=NUM) 
		{
			for(flag=1,k=1;flag&&k<i;k++) 
				if(a[k]==a[i])        flag=0;
			for(k=1;flag&&k<i;k++) 
				if((a[i]==a[k]-(k-i))||(a[i]==a[k]+(k-i))) flag=0;
			if(!flag) 
			{
				if(a[i]==a[i-1]) 
				{
					i--; 
					if(i>1&&a[i]==NUM)
						a[i]=1; 
					else if(i==1&&a[i]==NUM)
						not_finish=0; 
					else a[i]++; 
				}
				else if(a[i]==NUM) a[i]=1;
				else a[i]++; 
			}
			else if(++i<=NUM)
				if(a[i-1]==NUM) a[i]=1; 
				else a[i]=a[i-1]+1; 
		}
		if(not_finish)
		{
			for(k=1;k<=NUM;k++) 
				arr[count][k-1]=a[k]+48;
			if(a[NUM-1]<NUM) a[NUM-1]++; 
			else a[NUM-1]=1;
			i=NUM-1; 
			count++;
		}
	}
}
int cmp(const void *a,const void *b)
{
	return strcmp((char *)a,(char *)b);
}
int main()
{
	int m,n,i;
	process();
	qsort(arr,92,sizeof(arr[0]),cmp);
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&m);
		printf("%s\n",arr[m-1]);
	}
	return 0;
}

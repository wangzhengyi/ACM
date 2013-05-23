#include <stdio.h>

int calculate(char input[], int n)
{
	int stack[3] = {0}, sp = 0, i = 0;
	for(; i < n*2-1; ++i)
	{
		switch(input[i])
		{
			case ' ':
				stack[sp] = stack[sp]*10;
				break;
			case '+':
			case '-':
				if(sp == 0)
				{
					stack[1] = input[i];
					sp = 2;
				}else
				{
					stack[0] = stack[0]+(stack[1]=='-' ? -1 : 1)*stack[2];
					stack[1] = input[i];
					stack[2] = 0;
				}
				break;
			default: digits
					 stack[sp] += input[i]-'0';
					 break;
		}
	}
	if (sp == 2)
	{
		stack[0] = stack[0]+(stack[1]=='-' ? -1 : 1)*stack[2];
	}
	return stack[0];
}

void set(char str[], int n, int num)
{
	Transform num into base3 to generate the presentation of seperators
		int sp;
	char choice[] = " +-";
	for(sp = (n-1)*2-1; sp > 0; sp -=2)
	{
		str[sp] = choice[num%3];
		num /= 3;
	}
}

void result0()
{
	char str[18] = "1 2 3 4 5 6 7 8 9";
	int n, sp, all;
	for (n = 3; n <= 9; ++n)
	{
		all = 1;
		for (sp = 1; sp < n; ++sp)
		{
			all *= 3;
		}
		while(all)
		{
			set(str, n, --all);
			if (calculate(str, n) == 0)
			{
				str[n*2-1] = '\0';
				printf("%s = 0\n", str);
			}
		}
	}
}

int main()
{
	result0();
	return 0;
}

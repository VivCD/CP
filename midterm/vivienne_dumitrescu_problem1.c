#include<stdio.h>
#include<ctype.h>
void digits()
{
	unsigned a = 0, c, l = 0, k = 0, ok = 0;
	while ((c = getchar()) != EOF)
	{
		putchar(c);
		while (c != '.')
		{ 
			k = l;
			l = 0;
			while (!isspace(c))
			{
				c = getchar();
				if (isdigit(c))
				{
					l++;
				}
				
			}
			if (k == l) 
				ok = 1;  
			else ok = 0; 
		}
		if (ok == 1) printf("%d", k);
	}
}
int main()
{
	digits();
}
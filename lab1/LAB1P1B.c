#include<stdio.h>
#include<ctype.h>

void base16(unsigned n)
{
	while(n!=0)
	{
		if(n%16<=9)
		{
			printf("%d", n%16);
		}
		else if(n%16==10)
			putchar('A');
		else if(n%16==11)
			putchar('B');
		else if (n%16==12)
			putchar('C');
		else if (n%16==13)
			putchar('D');
		else if (n%16==14)
			putchar('E');
		else if (n%16==15)
			putchar('F');
		n=n/16;

	}
}

int main()
{
	printf("From left to right: ");
	base16(234612670);
	putchar(' ');
	return 0;
}
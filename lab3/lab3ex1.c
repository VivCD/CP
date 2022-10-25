#include<stdio.h>
#include<ctype.h>


int main()
{
	int ok=0;
	int c;
	while((c=getchar())!=EOF)
	{
		if(!isspace(c))
		{
			if(ok!=0) printf(" ");
			putchar(c);
			ok=0;
		}
		 else ok++;
	}
	return 0;
}



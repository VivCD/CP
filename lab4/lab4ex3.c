#include<stdio.h>
#include<ctype.h>
#include<limits.h>
#include<math.h>

int real()
{
	int c;
	int nr=0;
	while((c=getchar()) !='.')
	{
		nr=nr*10+(c- '0');
	}
	return nr;
}

float decimal()
{
	int c,num=0;
	float fr=0;
	while((c=getchar()) !=EOF)
	{
		fr=fr*10 + (c-'0');
	    num++;
	}
	fr=fr/pow(10,num);
	return fr;

}

int main()
{
	float x=real()+decimal();
	printf("\n %f \n",x);
	return 0;

}
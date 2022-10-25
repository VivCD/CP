#include<stdio.h>

unsigned getBit(unsigned n,unsigned pos)
{
    return ((n>>pos)&1);
}

unsigned setBit(unsigned n,unsigned pos,unsigned b)
{
    return n|(b<<pos);
}

int ReverseNibble(unsigned n)
{
	unsigned val=0,b0,b1,b2,b3;
	unsigned nrBits=sizeof(n)*8;
	for(int i=0;i<nrBits;i=i+4)
	{
		b0=getBit(n,i);
		b1=getBit(n,i+1);
		b2=getBit(n,i+2);
		b3=getBit(n,i+3);
		val=setBit(val,nrBits-4-i,b0);
		val=setBit(val,nrBits-4-i+1,b1);
		val=setBit(val,nrBits-4-i+2,b2);
		val=setBit(val,nrBits-4-i+3,b3);

	}
	return val;
}

int main()
{
	unsigned d=0xAE2B2;
	unsigned x=ReverseNibble(d);
	printf("%x",x);
	return 0;
}
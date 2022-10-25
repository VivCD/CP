#include <stdio.h>
#include <stdint.h>

uint8_t matchWords(uint64_t a, uint64_t b){
	uint8_t rez=0;
	for (int i=0; i<=8; i++){	//there are 8 Bytes in 64 bits
		if (((a>>(8*i)&0xFF))==((b>>(8*i))&0xFF)){
			rez=rez|(1<<i);	//we set bit on position i from rezult (onto 1)
		}
	}
	return rez;
}

int main(int argv, char **argc)
{
   uint64_t a=0ul;
   uint64_t b=0x000000ABul;
   printf("0x%x\n", matchWords(a, b));
}

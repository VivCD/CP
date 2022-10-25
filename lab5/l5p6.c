#include <stdint.h>
#include <stdio.h>



int32_t rotswap(uint32_t n)	
{
  printf("%x\n", n);		
  n = n << 4 | n >> 28;
  return n << 16 | n >> 16;	
}

unsigned minrot(int32_t n)
{
  int32_t crt = n, min = n;
  while ((crt = rotswap(crt)) != n)
    if (crt < min) min = crt;
  return min;
}

int main(void)
{
  printf("\n%x\n", minrot(0x12345678));
}
#include<stdio.h>
#include<stdint.h>



int f(uint16_t a, uint64_t b)
{
	unsigned nrBits = sizeof(b) * 8;
	unsigned nrBits2 = sizeof(a) * 8;
	unsigned byte1, byte2;
	unsigned count = 0, nrbyte = 0;
	for (int i = 0; i < nrBits; i = i + 8)
	{
		byte1 = ((b >> i) & 0xFF);
		for (int j = 0; j < nrBits2; j = j + 8)
		{
			byte2 = ((a >> j) & 0xFF);
			nrbyte++;
			if (byte1 == byte2)
				count++;
		}

	}
	if (count == nrbyte)
		return 1;
	else return 0;
}

int main()
{
	unsigned x = f(0x21BA, 0xA3B2D1F278);
	printf("%d\n", x);
	return 0;
}
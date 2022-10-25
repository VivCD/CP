#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* dig2text_en[]={
	"zero",
	"one", 
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

unsigned countFinalLength(const char *s){
	/*counts the non-digits and the legth of the words corresponding to the digits */
	int cnt=0;
	for (int i=0; s[i]; i++){
		if (!isdigit(s[i])){
			cnt++;
		}
		if (isdigit(s[i])){
			cnt=cnt+strlen(dig2text_en[s[i]-'0']);
		}
	}
	return cnt+1;
}

char* digitToText(const char *s)
{
	/* the lazy (and safe) way is to count how many digits you have and precompute the legth of the final string */
	unsigned newLen=countFinalLength(s);
	char* sNew=malloc(sizeof(char)*newLen);
	if (!sNew){
		return NULL;
	}
	memset(sNew, 0, newLen);	//zeroing the new area of mem; can be done with calloc too
	int n=0;	//index in the new string
	for (int i=0; s[i]; i++){
		if (isdigit(s[i])){
			strcat(sNew+n, dig2text_en[s[i]-'0']);
			n=n+strlen(dig2text_en[s[i]-'0']);
		}
		else{
			sNew[n]=s[i];
			n++;
		}
	}
	return sNew;
}

int main(int argv, char **argc)
{
    char* s="Ana are 12 mere si 13.5 pere";
    printf("New string is %s\n",digitToText(s));
}

#include <stdio.h>
 unsigned countSegments(unsigned n){
    unsigned counter = 0;
    unsigned size = sizeof(n)*8;
    for(int i = 0; i < size; i++){
       unsigned mask_1 = n & (1<<i);
        unsigned mask_2 = n & (1u << (i + 1)); //if two consecutive bits are different => a segment
        if((mask_1<<1) != (mask_2)) // if we left shift the first mask by 1 it should be equal to the 2nd mask => 1 segment else => not a segment
            counter ++;
 
 
    }
    return counter;
 }
 int main(){
    unsigned num = 3;
    printf("The number %d has %d segments of consecutive equal bits", num, countSegments(num));
    return 0;
 
 
 }
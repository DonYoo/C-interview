// read64bit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

unsigned int read64bit(unsigned int input64){
    unsigned int result = 0;
    
    unsigned int first = 0;
    unsigned int second = 0;

    first = input64 & 0xffffffff;

    second = (input64 & 0xffffffff00000000);

    int size = 32;
    while (size--){
	second >>= 1;
    }
    

    printf("first %x\n", first);
    printf("second %x\n", second);

    return result;
}
int _tmain(int argc, _TCHAR* argv[])
{
    unsigned int input[2];
    unsigned int fvalue = 0x12340000;		//64bits
    unsigned int svalue = 0x56780000;

    input[0] = fvalue;
    memcpy(input + 1, (unsigned int*)&svalue, sizeof(svalue));

    printf(" %x %x", *input, *(input+1));

    //printf("unsigned result %x", read64bit(input));
    return 0;
}


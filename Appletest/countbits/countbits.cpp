// countbits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int countbits(int input){
    int count = 0;

    while (input){
	if (input & 1){
	    count++;
	}
	input >>= 1;
    }
    return count;
}

int _tmain(int argc, _TCHAR* argv[])
{
    /*
    example 1
    count bits set in byte
    */

    int input = 0x01101;
    printf("count %d\n", countbits(input));

    return 0;
}


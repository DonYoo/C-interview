// reversed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>


/*  
     reverse bits of an integer that is a power of 2.
*/

unsigned int reverse(unsigned int num){
    unsigned int no_bits = sizeof(num) * 8;
    unsigned int reversed = 0;

    for (int i = 0; i < no_bits; i++){
	if ((num & (1 << i))){
	    reversed |= 1 << ((no_bits - 1) - i);
	}
    }
    return reversed;
}

unsigned int myReverse(unsigned int num){

    unsigned int result = 0;

    for (int i = 0; i < sizeof(num) * 8 - 1; i++){
	if (num & 1){
	    result += 1;
	}
	num >>= 1;
	result <<= 1;
    }
    return result;
}

unsigned int mySecond(unsigned int input){
    unsigned int result = 0;

    int size = sizeof(input) * 8 -1; // find how long is the number.

    // make Big O to log n. since if the input is zero it then shift the value.
    while (input != 0){
	if (input & 1){
	    result += 1;
	}
	input >>= 1;
	result <<= 1;
	size--;
    }

    while (size--){
	result <<= 1;
    }
    return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
    unsigned int input = 123456;    
    // this reversed the bits. not the side 
    // printf("int min %d\n", INT_MAX^input);

    printf("function %u\n", reverse(input));

    printf("mine %u\n", myReverse(input));

    printf("opt mine %u\n", mySecond(input));

    return 0;
}


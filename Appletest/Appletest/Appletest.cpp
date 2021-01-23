// Appletest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;



int getElement(int *input1, int size1, int *input2, int size2, int k){

    printf("%d ", input1[0]);
    printf("%d\n", input2[0]);

    int half = k / 2;

    // if any inputs are invalid.
    if ((size1 + size2 < k) || (k < 1)){
	return -1;
    }
    
    // if k is 1
    if (k == 1){
	if (size1==0){
	    return input2[k - 1];
	}
	else if (size2==0){
	    return input1[k - 1];
	}
	return std::min(input1[k-1], input2[k-1]);
    }

    // compare value of 2 arrays
    if (input1[std::min(size1, half) - 1] < input2[std::min(size2, half) - 1]){
	return getElement(input1 + half, size1 - half, input2, size2, half + k%2);
    }
    else{
	return getElement(input1, size1, input2 + half, size2 - half, half + k%2);
    }
}

int main()
{

    

    /*
    example 2
    given 2 sorted arrays, get the i-th element without sorting to a single array.

    */

    int input1 [5] = {2, 3, 6, 7, 9};
    int input2 [4] = {1, 4, 8, 10};
    int k = 9;

    // size whole array / size of 1 arraysize.
    int size1 = sizeof(input1) / sizeof(input1[0]);
    int size2 = sizeof(input2) / sizeof(input2[0]);

    printf("i-th element %d\n", getElement(input1, size1, input2, size2, k));


    return 0;
}


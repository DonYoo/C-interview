// memoryManage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h> // memory allocation functions are kept in the header

int _tmain(int argc, _TCHAR* argv[])
{
    // init
    int *input = (int*) malloc(sizeof(int) * 2);
    // you have to free it before making a new
    free(input);

    // malloc can hold undefined value.
    // calloc allocate with a zero.
    input = (int*)calloc(2, sizeof(int));

    if (input == NULL){
	fprintf(stderr, "Unable to allocate enough memory for input\n");
    }
    // get memory

    *input = 1;
    *(input + 1) = 2;
    
    // full of memory space
    // get 2 more space
    input = (int *)realloc(input, sizeof(int) * 6);

    *(input + 2) = 3;
    *(input + 3) = 4;


    // free memory
    int size = sizeof(input) / sizeof(input[0]);

    size = 6;

    printf("size : %d\n", size);

    printf("original\n");
    for (int i = 0; i < size; i++){
	printf("%d", input[i]);
    }

    printf("\n");

    for (int i = 0; i < size; i++){
	input[i] = 0;
    }

    printf("free memory\n");

    for (int i = 0; i < size; i++){
	printf("%d", input[i]);
    }
    printf("\ndon't do this since dangling pointer would give problem\n");

    free(input);
    puts((char*)input);


    return 0;
}


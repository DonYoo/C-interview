

#include <iostream>

void* myMemcpy(void* dest, void* source, unsigned int size){

    char* newDest = (char *)dest;			// char is 1 byte
    char* newSour = (char *)source;

    char* newTemp = new char[size];

    for (int i = 0; i < size; i++){
	newTemp[i] = newSour[i];
    }

    for (int i = 0; i < size; i++){
	*newDest = *newTemp;				// cpy value
	newDest++;					// next address
	newTemp++;
    }
    return dest;
}

int main(){

    // sameple of memcpy

    char string[] = "Hello this is Don";
    int size = sizeof(string) / sizeof(string[0]) - 1;	// this work since size is static.

    char* ptr = string;

    int size2 = sizeof(ptr);				// this is wrong since it only gives size of the char
    // The compiler doesn't know what the pointer is pointing to
    size2 = strlen(ptr);				// use strlen instead to get the full length of string

    printf("size of string %d\nsize of pointer %d\n", size, size2);

    char *memory = (char*)malloc(18 * sizeof(char));	// this is the pointer. not an array so doesn't know the size.

    memcpy(memory, string, 18);

    printf("test %d \n", strlen(memory));

    memory[strlen(memory)] = '\0';

    printf("memory : %s\n", memory);


    free(memory);

    myMemcpy(memory, string, 18);

    printf("memory : %s\n", memory);

    /*
    memmove can prevent overlap. memcpy cannot.
    */

    char strings[] = "stackoverflow";
    char *third, *fourth;
    third = strings;

    char strings2[] = "stackoverflow";
    fourth = strings2;

    puts(strings);
    memcpy(third + 5, third, 7);
    puts(third);

    memmove(fourth + 5, fourth, 7);
    puts(fourth);
    
    /*
    char csrc[100] = "Geeksfor";
    myMemcpy(csrc + 5, csrc, strlen(csrc) + 1);
    printf("%s", csrc);
    */
}
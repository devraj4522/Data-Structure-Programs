#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct useArray
{
    int capacity;
    int size;
    int *ptr;
};

void createArrayfun(struct useArray *a, int capacity){
    a->capacity = capacity;
    a->ptr = (int *)malloc(capacity*sizeof(int));
}

void populateArray(struct useArray *a, int size){
    a->size = size;
    for (int i = 0; i < size; i++)
    {
        scanf("%d", (a->ptr) + i);
    }
    
}
void displayArray(struct useArray *a){
    for (int i = 0; i < a->size; i++)
    {
        printf("\n%d", *((a->ptr)+i));
    }
    
}

int main() {
    int capacity, size;
    struct useArray *createArray;
    printf("Enter the value for size of Array to create: ");
    scanf("%d", &capacity);    
    printf("How many Element Do you want to create: ");
    scanf("%d", &size);    
    createArrayfun(createArray, capacity);
    populateArray(createArray, size);
    displayArray(createArray);

    // Report 
    // You have create: 
    printf("\n An array with %d capacity having %d numbers of items", createArray->capacity, createArray->size);
    return 0;
}

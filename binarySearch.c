#include <stdio.h>
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


int binarySearch(int *arr, int size, int value_to_find)
{
    int max = size - 1, min = 0, mid;
    while (max != min)
    {
        mid = (max + min) / 2;
        if (*(arr + mid) == value_to_find)
        {
            printf("\nFound at position%d", mid);
            return 1;
        }
        else
        {
            if (*(arr + mid) > value_to_find)
            {
                max = mid - 1;
            }
            else
            {
                min = min + 1;
            }
        }
    }
    printf("\nNot Found");
    return -1;
}

int main()
{
    struct useArray *array;
    int capacity, value_to_find;
    printf("\nEnter the size of Array you want to create: ");
    scanf("%d", &capacity);
    // Keeping the size of array same as capacity to use only
    // Required space.
    createArrayfun(array, capacity);
    printf("\nEnter Value \n(Ascending Order): ");
    populateArray(array, capacity);
    displayArray(array);
    printf("\nEnter Value to find in Array: ");
    scanf("%d", &value_to_find);
    int find = binarySearch(array->ptr, capacity, value_to_find);
}

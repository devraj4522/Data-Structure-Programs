
#include <stdio.h>
#include <stdlib.h>

struct useArray
{
    int capacity;
    int size;
    int *ptr;
};

void IsEmpty(int size)
{
    if (size)
    {
        printf("\nArray is not Empty");
    }
    else
    {
        printf("\nEmpty.");
    }
}
void CreateArrayfun(struct useArray *a, int capacity)
{
    a->capacity = capacity;
    a->ptr = (int *)malloc(capacity * sizeof(int));
}

void InsertItesm(struct useArray *a, int numOfItems)
{
    a->size = numOfItems;
    for (int i = 0; i < numOfItems; i++)
    {
        scanf("%d", (a->ptr) + i);
    }
}
void DisplayArray(struct useArray *a, int numOfItems)
{
    for (int i = 0; i < numOfItems; i++)
    {
        printf("\n%d", *((a->ptr) + i));
    }
}

void Search(int arr[], int n, int val)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == val)
            printf("\nFound at position %d", i);
}

int DeleteElement(int *arr, int n, int val)
{
    // Search x in array
    int i;
    for (i = 0; i < n; i++)
        if (*(arr + i) == val)
            break;

    // If x found in array
    if (i < n)
    {
        // reduce size of array and move all
        // elements on space ahead
        n = n - 1;
        for (int j = i; j < n; j++)
            *(arr + j) = *(arr + j + 1);
    }

    return n;
}

int main()
{
    int capacity, size, search, delIndex, del, choice;
    struct useArray *createArray;
    printf("Enter the value for size of Array to create: ");
    scanf("%d", &capacity);
    printf("How many Element Do you want to create: ");
    scanf("%d", &size);
    CreateArrayfun(createArray, capacity);
    InsertItesm(createArray, size);

    printf("Given Array is : ");
    DisplayArray(createArray, size);

    // Report
    // You have create:
    printf("\n An array with capacity - %d having %d numbers of items is created", createArray->capacity, createArray->size);

    while (1)
    {
        printf("\nEnter the Choice \n 1 - For Search \n 2 - for delete.\n 3 - for Empty\n 0 - to Exit\n ");
        scanf("%d", &choice);
        if (choice != 0)
        {
            switch (choice)
            {
            case 1:
                // Search item with parameters in the function as size and value to be searched.
                printf("\nEnter the value to search in the List.");
                scanf("%d", &search);
                Search(createArray->ptr, size, search);
                break;
            case 2:
                // Check the list is Empty or not.
                // Delete Elemet.
                printf("\nEnter the value to delete in the List.");
                scanf("%d", &del);
                delIndex = DeleteElement(createArray->ptr, size, del);
                printf("\nDelete Index = %d \n");
                printf("Given Array is : ");
                DisplayArray(createArray, size - 1);
                break;
            case 3:
                // IsEmpty
                IsEmpty(size);
            default:
                break;
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}
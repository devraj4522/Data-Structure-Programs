/******************************************************************************

                            Deletion Using Array

*******************************************************************************/

#include <stdio.h>

void take_input(int arr[5])
{
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", (arr + i));
    }
    
}
void display(int arr[5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("\narray[%d] %d", i , *(arr + i));
    }
}

int main()
{
    int arr[10];
    int pos;
    printf("\nEnter values :");
    take_input(arr);
    printf("\nValues you entered :");
    display(arr);
    printf("\nEnter postion to be deleted.");
    scanf("%d", &pos);
    for (int  i = pos; i < (5 -1); i++)
    {
        arr[i] = arr[i + 1];
    }
    for (int j = 0; j < 5-1; j++)
    {
        printf("\narray[%d] %d", j , *(arr + j));
    }
    
    return 0;
}
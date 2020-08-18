// - Write a function which take input an item and
//  retrun the item who is previous item of that item. 
//  [ Example 34, 56, 78,90: The previous item of 78 is 56]

#include<stdio.h>

int PreviousOf(int *arr, int val, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (*(arr + i) == val )
        {
            return *(arr + i -1);
        }
        
    }
    if (*(arr + i) != val)
    {
        return -1;
    }
}

void Display(int *arr, int  size){
    int i;
    for ( i = 0; i < size; i++)
    {
        printf("\n%d", i);
    }
    
}

int main(){
    int arr[5] = {1,2,3,4, 5};
    int val, prev;
    printf("Array elements are :\n");
    Display(arr, 5);
    printf("\n Enter value from the above given numbers.");
    scanf("%d", &val);
    prev = PreviousOf(arr,val, 5);
    if (prev != -1)
    {
        printf("Previous of the given value is %d", prev);
    }
    else
    {
        printf("\nNot Valid");
    }
    
}
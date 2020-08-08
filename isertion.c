// Insertion in c Programming

#include <stdio.h>
 
void take_input(int *ptr, int num)
{
    for (int i = 0; i < num; i++)
    {
        scanf("%d", (ptr + i) );
    }
    
} 
void display(int *ptr, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("\n%d", *(ptr + i) );
    }
    
}

void insertion(int *array, int position, int value, int num){
    for (int c = num - 1; c >= position; c--)
      array[c+1] = array[c];
 
    array[position] = value;
}

int main()
{
    int array[100], position, c, n, value;

    printf("Enter number of elements in array\n");
    scanf("%d", &n);
 
    printf("Enter %d elements\n", n);
    take_input(array, n);
 
    printf("Enter the location where you wish to insert an element\n");
    scanf("%d", &position);
 
    printf("Enter the value to insert\n");
    scanf("%d", &value);
 
    insertion(array, position, value, n);
    printf("Resultant array is\n");
 
    display(array, n+1);
 
   return 0;
}
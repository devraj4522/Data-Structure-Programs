// Given an array, of size n , reverse it.

// Sample Input
// 6
// 16 13 7 2 1 12 

// Sample Output
// 12 1 2 7 13 16 

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    /* Write the logic to reverse the array. */

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    
    for(i = num -1 ; i >= 0; i--)
        printf("%d ", *(arr + (i)));
    
    return 0;
}

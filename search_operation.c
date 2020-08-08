#include <stdio.h> 
  
int search(int arr[], int n, int val) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == val) 
            return i; 
    return -1; 
} 
  
int main(void) 
{ 
    int arr[5];
    printf("Enter Values\n");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &arr);
    }
     
    int val;
    printf("Enter the value to search:\n");
    scanf("%d", val); 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = search(arr, n, val); 
    if (result == -1)
    {
        printf("Not Found");
    }
    else
    {
        printf("Found at Position %d", result);
    }
    
    return 0; 
} 
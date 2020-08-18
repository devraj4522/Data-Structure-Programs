#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void Display(int *arr, int n)
{
    int len = 2*n -1;
    for (int  i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            printf("%d ", *(arr + i + j));
        }
        printf("\n");
    }
}

int pattern(int *arr, int n) //*arr, n =3
{
    int static pos=0;
    int static lineChange=0; //pos= linechange =0
    int len  = 5; //len = 2
    int max = len*lineChange + pos + (len)*(len - 2*lineChange - 1); // 0 + 5*4
    int init = len*lineChange + pos; 
    if (pos==len/2)
    {
        max = init +1;
    }
    
    for (int  i = init; //0
    i <= max; i = i+ len) // 5 
    {
        for (int j = 0; j < len -(2*pos); j++) //0, 1,2, 3, 4
        {
            *(arr + (i+j) )= n;
        }
        
    }
    if (pos==len/2)
    {
        return 0;
    }
    pos++;
    lineChange++;
    int pat = pattern(arr, n-1);
    return 0;
}


int main() 
{

    int n, i, j;
    int min, count;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n-1; j++)
        {
            min = i<j ? i:j;
            count = n-min;
            printf("%d ", count);
        }
        for ( j = n-1; j >=0; j--)
        {
            min = i<j ? i:j;
            count = n-min;
            printf("%d ", count);
        }
        printf("\n");
    }
    
    for ( i = n; i < 0; i++)
    {
        for ( j = 0; j < n-1; j++)
        {
            min = i<j ? i:j;
            count = n-min;
            printf("%d ", count);
        }
        for ( j = n-1; j >=0; j--)
        {
            min = i<j ? i:j;
            count = n-min;
            printf("%d ", count);
        }
        printf("\n");
    }
        
    
    for ( i = n -2; i >= 0; i--)
    {
        for ( j = 0; j < n-1; j++)
        {
            min = i<j ? i:j;
            count = n-min;
            printf("%d ", count);
        }
        for ( j = n-1; j >=0; j--)
        {
            min = i<j ? i:j;
            count = n-min;
            printf("%d ", count);
        }
        printf("\n");
    }
        

    return 0;
}
/******************************************************************************

                            Swap Operation Call By value and call by Reference.

*******************************************************************************/

#include <stdio.h>

void call_by_value(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("Swaped values --- Call by --- Val (a,b):\n %d %d",a,b);

    
}
void call_by_ref(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a;
    int b;
    printf("Enter 2 val: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("\n a and b are %d %d\n", a,b);
    call_by_value(a,b);
    printf("\nEnter 2 val: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    call_by_ref(&a, &b);
    printf("\nSwaped values --- Call by --- Reference ---- (a,b): \n%d %d",a,b);
    return 0;
}

# include<stdio.h>
#include<stdlib.h>

// Create an Array stack of ADT
struct ArrayStack
{
    int top;
    int size;
    int *array;
};

struct ArrayStack *CreateStack(int sizetopass){
    struct ArrayStack *stack;
    stack = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
    stack->top = -1;
    stack->size = sizetopass;
    stack->array = (int *)malloc(sizeof(int) * sizetopass);
    return stack;
}

int isFull(struct ArrayStack *stack){
    if (stack->top == stack->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct ArrayStack *stack){
    if (stack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
     
}

int  push(struct ArrayStack *stack, int item){
    if (isFull(stack)) 
        {
            return -1;
        }
    int val = ++stack->top;
    printf("%d", val);
    stack->array[val] = item; 
    return 0;
}

int pop(struct ArrayStack *stack){
    if (!(isEmpty(stack)))
    {
        int item = stack->array[stack->top];
        return stack->array[stack->top--]; 
    }
    return -1;
}

void display(struct ArrayStack *stack)
{
    if(!(isEmpty(stack)))
    {
        printf("\n The elements of the given stack \n");
        for(int i=stack->top; i>=0; i--)
            printf("\n%d",stack->array[i]);
    }
    else
    {
        printf("\n The STACK is empty");
    }
   
}

int main(){
    
    int size, choice, itemValue, p; 
    struct ArrayStack *stack;
    fflush(stdin);
    scanf("%d", &size);
    stack = CreateStack(size);
    printf("Enter Choice --->\n\t 1.push\n\t 2.pop\n\t 3.display\n\t 4.exit");
    do
    {
        printf("\n Enter the Choice:");
        fflush(stdin);
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("\n Enter the value to be pushed: ");
                fflush(stdin);
                scanf("%d", &itemValue);
                push(stack, itemValue);
                break;
            }
            case 2:
            {
                pop(stack);
                break;
            }
            case 3:
            {
                display(stack);
                break;
            }
            case 4:
            {
                printf("\n\t EXIT from choice ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice Enter Choice --->\n\t 1.push\n\t 2.pop\n\t 3.display\n\t 4.exit");
            }
                
        }
    }
    while(choice!=4);
    return 0;

}

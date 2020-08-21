/********************
 * Create 3 stack A, B, C
 * Value is Entered through only stack A
 * Value is transfered from A to B to C 
 * So that,At First C is filled then B then At last A
 * ************************/
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

int  display(struct ArrayStack *stack1, struct ArrayStack *stack2, struct ArrayStack *stack3)
{
    if (!(isEmpty(stack1)))
    {
        printf("\n The elements of the given stack1");
        for (int i = stack1->top; i >= 0; i--)
            printf("\n value = %d for element %d\n", stack1->array[i], i);
    }
    else
    {
        printf("\n Stack 1 is empty");
    }

    if (!(isEmpty(stack2)))
    {
        printf("\n The elements of the given stack2 \n");
        for (int i = stack2->top; i >= 0; i--)
            printf("\n value = %d for element %d", stack2->array[i], i);
    }
    else
    {
        printf("\n Stack 2 is empty");
    }

    if(!(isEmpty(stack3)))
    {
        printf("\n The elements of the given stack3 \n");
        for(int i=stack3->top; i>=0; i--)
            printf("\n value = %d for element %d",stack3->array[i], i);
    }
    else
    {
        printf("\n Stack 3 is empty");
    }
}

void transferElementFromStackToOther(struct ArrayStack *stack1, struct ArrayStack *stack2 )
{
    int temp;
    temp = pop(stack1);
    push(stack2, temp);
}

int recTransferEachOther(struct ArrayStack *stack1, struct ArrayStack *stack2, struct ArrayStack *stack3){
    if (!isFull(stack3))
    {
        printf("\nValue is going in stack1 -> stack 2 ->stack3\n ");
        transferElementFromStackToOther(stack1, stack2);
        transferElementFromStackToOther(stack2, stack3);
        return 0;
    }
    else if (!isFull(stack2))
    {
        printf("Value is going in stack1 ->");
        transferElementFromStackToOther(stack1, stack2);
        return 0;
    }
    else if (!isFull(stack1))
    {
        printf("Only stack 1 is empty and value is going in stack 1 directly");
        return 0;
    }
    else
    {
        printf("All the stacks are full");
        return 0;
    }
}

void chooseAndDoOperation(struct ArrayStack *stack1, struct ArrayStack *stack2, struct ArrayStack *stack3){
    int choice, itemValue;
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
                push(stack1, itemValue);
                recTransferEachOther(stack1, stack2, stack3);
                break;
            }
            case 2:
            {
                pop(stack1);
                break;
            }
            case 3:
            {
                display(stack1, stack2, stack3);
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
}

int main(){
    
    int size, choice, p; 
    // struct ArrayStack *stack;
    struct ArrayStack *stack1;
    struct ArrayStack *stack2;
    struct ArrayStack *stack3;
    fflush(stdin);
    
    printf("Enter the size of the Stack");
    scanf("%d", &size);
    stack1 = CreateStack(size);
    stack2 = CreateStack(size);
    stack3= CreateStack(size);
    printf("Enter Choice --->\n\t 1.push\n\t 2.pop\n\t 3.display\n\t 4.exit");
    // if (isFull(stack1) )
    // {
    //     transferElementFromStackToOther(stack1, stack2);
    // }    
    
    chooseAndDoOperation(stack1, stack2, stack3);
    return 0;
}

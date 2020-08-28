#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 

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


// Function to return postfix
int evaluatePostfix(char* exp) 
{ 
    // Create a stack
    struct ArrayStack *stack = CreateStack(strlen(exp)); 
    int i; 
    

    // Main For loop  //123+*
    for (i = 0; exp[i]; ++i) 
    { 
        
        if (isdigit(exp[i]))

            push(stack, exp[i] -'0');  
  
        
        else
        { 
            int operataion_1 = pop(stack); 
            int operataion_2 = pop(stack); 
            switch (exp[i]) 
            { 
            case '+': 
                push(stack, operataion_2 + operataion_1); 
                break; 
            case '-': 
                push(stack, operataion_2 - operataion_1);
                break; 
            case '*': 
                push(stack, operataion_2 * operataion_1); 
                break; 
            case '/': 
                push(stack, operataion_2/operataion_1); 
                break; 
            } 
        } 
    } 
    return pop(stack); 
} 

int main(){
    
    char exp[100]; //ans = acd*f/+
    printf("Enter the expression to be evaluated");
    scanf("%s", exp);
    printf ("Infix to postfix = : %d", evaluatePostfix(exp)); 
    return 0;
    

}

#include<stdio.h>
#include<stdlib.h>

int top =-1;
int size;
int *array;

int isFull(){
    if (top==size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(){
    if (top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(int data){
    if (!isFull())
    {
        top = top +1;
        array[top] = data;
        return data;
    }
    else
    {
        printf("Stack is full.");
        return -1;
    }
}
int pop(){
    if (!isEmpty())
    {
        int data = array[top];
        top--;
        return data;
    }
    else
    {
        printf("Stack is Empty.");
        return -1;
    }
}
void display(){
    if (top==-1)
    {
        printf("\nstack is empty");
        exit(0);
    }
    
    for (int i = top; i >= 0; i--)
    {
        printf("\n\t Element %d is %d", i, array[i]);
    }
    // printf("%d", top);
}

int main(){
    int choice, itemValue;

    //Creat array dynamically
    printf("Enter the size of stack: ");
    scanf("%d", &size);
    array = (int *)malloc(sizeof(int)*size);
    do
    {
        printf("\n Enter the Choice:");
        printf("Enter Choice --->\n\t 1.push\n\t 2.pop\n\t 3.display\n\t 4.exit");
        fflush(stdin);
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("\n Enter the value to be pushed: ");
                scanf("%d", &itemValue);
                push( itemValue);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
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

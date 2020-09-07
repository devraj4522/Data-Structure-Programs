#include<stdio.h>
#include<stdlib.h>
#define SIZE  5

// Create an array for queue implimentation.
int arr[SIZE];
// Put the front and rare at 0
int front = 0;
int rare = 0;

int isFull()
{
    if (rare == SIZE)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if (rare == front)
        return 1; //Yes
    else
        return 0; //No empty ==false
}

void enqueue(int val)
{
    if (front == rare && rare != 0)
        printf("\nQueue is full.");
    else
        arr[rare++] = val;
}

int dequeue()
{
    if (isEmpty())
        {
        printf("\nQueue is Empty");
        return 0;
        }
    else
        return arr[front++];
}


int peak(){
    if (!isEmpty(rare, front))
        return arr[rare -1];
    else
    {
        printf("\nArray is empty");
        return 0;        
    }
}

void display()
{
    if (isEmpty())
        printf("\nArray is empty");        
    else
        {
        // Display
        for (int i = front; i < rare; i++)
        {
            printf("\nValue  = %d", arr[i]);
        }
        
    }
}
int main()
{

    int choice, val;
    while (1)
    {
        printf("\nEnter 1 for Enqueue 2 for Dequeue, \n3 for display and \nany other key to exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the value to Enqueue");
            scanf("%d",  &val);
            enqueue(val);
            break;
        case 2:
            printf("\nDequeueed %d", dequeue());
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
    
}

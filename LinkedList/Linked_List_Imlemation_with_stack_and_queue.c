#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

// Push the node at the begining of the list
void push(node **head, char data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;

    // Finally head is pointing to the last added node so that when we
    // want to travel last node we will accesse the head pointer which is
    // Pointint to the null.
    *head = new_node;
}


int pop_stack(node **head)
{
    node *ptr = *head;
    int val = 0;
    if (head == NULL)
        return val;
    else
    {
        val = ptr->data;
        *head = ptr->next;
        free(ptr);
        return val;
    }
}

node *front = NULL;
node *rear = NULL;
void enqueue(char data)
{
    node *new = (node *)malloc(sizeof(node));
    new->next = NULL;
    new->data = data;
    if (front == NULL && rear == NULL)
    {
        front = rear = new;
        return;
    }
    rear->next = new;
    rear = new;
}
 
int dequeue()
{
    char val;
    node *temp = front;
    if (front == NULL) return 0;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        val = front->data;
        front = front->next;
    }
    free(temp);
    return val;
}

// head is pointing to the last node in the LL so to reach the last add node  point to
// the head. So pass the head in the node.
void Print(node *node)
{
    while (node != NULL)
    {
        printf("\n ===== Element is %d ======", node->data);
        node = node->next;
    }
}

void stack_implementaion(node **head)
{
    while (1)
    {
        printf("\n Enter 1 for putting value\n 2 for removing element\n 3 to print and \n any key for exit");
        int ch, data;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter data to push");
            scanf("%d", &data);
            push(head, data);
            break;
        case 2:
            printf("popped %d", pop_stack(head));
            break;
        case 3:
            Print(*head);
            break;
        default:
            break;
        }
    }
    
}

void queue_implementation()
{
    while (1)
    {
        printf("\n Enter 1 for putting value\n 2 for removing element\n 3 to print and \n any key for exit");
        int ch, data;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter data to enqueue");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            printf("dequeued %d", dequeue());
            break;
        case 3:
            Print(front);
            break;
        default:
            break;
        }
    }
    
}


int main()
{
    node *head = NULL;
    while (1)
    {
        printf("\nEnter:\n 1 - For stack and 2 for queue\n");
        int ch;
        scanf("%d", &ch);
        fflush(stdin);
        switch (ch)
        {
        case 1:
            stack_implementaion(&head);
            break;
        case 2:
            queue_implementation();
            break;
        default:
            printf("\nError!");
            exit(0);
        }
    }
    return 0;
}

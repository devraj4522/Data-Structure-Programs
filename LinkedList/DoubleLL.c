// 1. The Double linked list and its ADT -  Create, ADD, DELETE Node

// 2. Circular liked list for circular queue.

#include<stdio.h>
#include<stdlib.h>

// ADT Node Creation
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

typedef struct Node node;

void create(node **head)
{
    *head = NULL;
}

void Add(node **headptr, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    node *head = *headptr;

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL)
    {
        head->prev = new_node;
    }
    *headptr = new_node;     
}

int deleteNode(node **headptr)
{
    node *head = *headptr;
    if (head == NULL)
    {
        printf("\n List is Empty.");
        return -1;
    }

    node *temp = head;
    int to_be_returned = temp->data;
    // If only one node. 
    if (head->next == NULL)
    {
        *headptr = NULL;
        free(temp);
    }
    else
    {
        *headptr = head->next;
        head->prev = NULL;
        free(temp);
    }

    return to_be_returned;
}

void display(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

void main()
{
    node *head;
    create(&head);
    
    int choice;
    int value;

    while (1)
    {   
        printf("\n Enter 1 for Add 2 for delete and 3 for display any other key to exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter value to be added.");
            scanf("%d", &value);
            Add(&head, value);
            break;
        
        case 2:
            printf("\ndeleted: %d", deleteNode(&head));
            break;
        
        case 3:
            printf("\n Values are :");
            display(head);
            break;
        
        default:
            exit(1);
        }
    }
}

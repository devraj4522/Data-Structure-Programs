#include<stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

// Push the node at the begining of the list
void push(node **head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = *head;

    // Finally head is pointing to the last added node so that when we 
    // want to travel last node we will accesse the head pointer which is 
    // Pointint to the null.
    *head = new_node;
}

// Previous node is give 
// 1. If previous node is null then nothing can be inserted after null
// 2. Else insert after the previous
void insertAfterPrev(node *prev, int data)
{
    if (prev == NULL)
    {
        return;
    }
    
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
}

// head is pointing to the last node in the LL so to reach the last add node  point to 
 // the head. So pass the head in the node.
void traverse(node *node)
{
    int i = 1;
    while (node != NULL)
    {
        printf("\n ===== Element %d is %d ======", i++, node->data);
        node = node->next;
    }
    
}

void insertAtEnd(node *nodes, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    node *ptr = nodes;
    new_node->data = data;
    if (nodes == NULL)
    {
        printf("\nThe Linked List is empty");
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    
    
}

int main()
{
    node *head = NULL;
    // The head is pointing to null;
    
    //Push elements one by one.
    push (&head, 1);
    push (&head, 5);
    push (&head, 6);
    push (&head, 9); //Now head is pointing to this last node.

    // Insert after the given previous in the function.
    // insertAfterPrev(head->next, 90);
    
    insertAtEnd(head, 4);
    // Traverse the linked List.
    traverse(head);
    return 0;
}

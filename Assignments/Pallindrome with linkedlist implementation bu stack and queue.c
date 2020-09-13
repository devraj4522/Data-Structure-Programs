#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

struct Node
{
    char data;
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
// void dequeue(node **head, char data)
// {
//     node *new_node = (node *)malloc(sizeof(node));
//     new_node->data = data;
//     new_node->next = *head;

//     // Finally head is pointing to the last added node so that when we
//     // want to travel last node we will accesse the head pointer which is
//     // Pointint to the null.
//     *head = new_node;
// }

char pop_stack(node **head)
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
 
char dequeue()
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

// 😃Pallindrome function
void pallindrome_stack(node **head)
{
    //Push elements one by one.
    char string1[100], string2[100];
    int i = 0;
    printf("\nEnter some magic word in stack:\n ");
    gets(string1);
    while (string1[i] != '\0')
        push(head, string1[i++]);
    i = 0;
    while (string1[i] != '\0')
        string2[i++] = pop_stack(head) ; 
    string2[i] = '\0';
    strcmp(string1, string2) == 0? printf("Is Pallindrome"): printf("Is not pallindrome");
}

void pallindrome_queue()
{
    //Push elements one by one.
    char string1[100], string2[100];
    int i = 0;
    printf("\nEnter some magic work in queue:\n ");
    gets(string1);
    while (string1[i] != '\0')
        enqueue(string1[i++]); 
    i = 0;
    while (string1[i] != '\0')
        string2[i++] = dequeue() ; 
    string2[i] = '\0';
    strcmp(string1, string2) == 0? printf("Is Pallindrome"): printf("Is not pallindrome");
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



int main()
{
    node *head = NULL;
    while (1)
    {
        printf("\nEnter 1 for stack and 2 for queue\n");
        int ch;
        scanf("%d", &ch);
        fflush(stdin);
        switch (ch)
        {
        case 1:
            pallindrome_stack(&head);
            break;
        case 2:
            pallindrome_queue();
            break;
        case 3:
            Print(head);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}

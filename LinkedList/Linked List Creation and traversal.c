#include<stdio.h>
#include<stdlib.h>

// Structure for Node type creation in linked list
struct Node{
    int data;
    struct Node *ptr;
};

// Display Data
void traverseLinkedList(struct Node *trav){
    while (trav !=NULL)
    {
        printf("\n%d Element", trav->data);
        trav->ptr;
        trav++;
    }
    
}

int main(){
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    // Allocating memory in the heap.
    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    



    // Head Node Data and pointer filling;
    head->data = 1;
    head->ptr = first;

 
    // First Node Data and pointer filling;
    first->data = 2;
    first->ptr = second;
     
    // second Node Data and pointer filling;
    second->data = 3;
    second->ptr = third;
     
    // third Node Data and pointer filling;
    third->data = 4;
    third->ptr = NULL;

    traverseLinkedList(head);


    return 0;     

}

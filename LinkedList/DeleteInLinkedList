#include<stdio.h>
#include<stdlib.h>

// Structure for Node type creation
struct Node{
    int data;
    struct Node *ptr;
};

// Display Data
void traverseLinkedList(struct Node *trav){
    while (trav !=NULL)
    {
        printf("\n%d Element", trav->data);
        trav = trav->ptr;
        // trav++;
    }
    
}

// // Deletion of First Node in the linked list.
// struct Node * deleteFirst(struct Node *head){
//     printf("\n%d ---%d ---%d ---%d", head, head->ptr, &head->ptr, &head->data);
//     head = head->ptr;
//     printf("\n%d ---%d ---%d ---%d", head, head->ptr, &head->ptr, &head->data);
//     return head;
// }

// Delete the first element.
struct Node * deleteFirst(struct Node *head){
    head = head->ptr;
    return head;
}

// Deletion in at any index in the linked list.
void  deleteAtAnyIndex(struct Node *head, int index){
    struct Node *ptr1, *ptr2;
    ptr1 = head;
    int i =0;
    while (i != index -1)
    {
        ptr1 = ptr1->ptr;
        i++;
    }
    ptr2 = ptr1->ptr;
    ptr1->ptr = ptr2->ptr;
}

// Delete with the given value.
void  deleteWithGivenValue(struct Node *head, int val)
{
    struct Node *ptr1, *ptr2;
    ptr1 = head;
    ptr2 = head->ptr; //One step ahead of of ptr1
    
    // If head->data = value 
    // Then return the program with the next addres and in the main program
    // as  head = head->next. So I am directly returning the program.
    if (head->data == val)
    {
        return;
    }
    
    while ((ptr2->data !=val ) && ptr2->ptr != NULL)
    {
        ptr1 = ptr1->ptr;
        ptr2 = ptr2->ptr;
    }
    if (ptr2->data == val)
    {
        ptr1->ptr = ptr2->ptr;
        printf("\n Deleted  %d\n", ptr2->data);
    }
    return;
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

    printf("\nTraversal Before Insertion.");
    traverseLinkedList(head);
    // head = deleteFirst(head);
    
    //========= Delete with the given value ===========
    int delete;
    printf("\nEnter the value to be deleted: ");
    scanf("%d", &delete);
    if (delete == head->data)
    {
        head  = head->ptr;
    }
    else
    {
        deleteWithGivenValue(head, delete);
    }
    //========= Delete with the given value ===========

    // deleteAtAnyIndex(head, 0);
    printf("\nTraversal After Deletion.");
    traverseLinkedList(head);
    return 0;     

}

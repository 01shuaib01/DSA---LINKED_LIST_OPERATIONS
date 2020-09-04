#include <stdio.h>  //Header File
#include <stdlib.h> //Header File Which contain malloc() and free() functions.

    //<---------------------Creating Node or list------------------->
struct Node
{
    int data;
    struct Node *next;                  //*next is point to the next Node
};

void Display_Element(struct Node *head);                                    //Declaration of Display all element in the Linked List.
struct Node *Insert_first(struct Node *head);                               //Declaration of insert at the begining. 
struct Node *Insert_Between(struct Node *head, int index);                  //Declaration of insert in Between.
struct Node *Insert_end(struct Node *head);                                 //Declaration of insert at the End.
struct Node *Insert_AfterNode(struct Node *head, struct Node *prevNode);    //Declaration of insert after the Node.

struct Node *Delete_first(struct Node *head);                               //Declaration of Deletion at the begining
struct Node *Delete_Index(struct Node *head, int index);                    //Declaration of Deletion in Between.
struct Node *Delete_Last(struct Node *head);                                //Declaration of Deletion at the End.
struct Node *Delete_Value(struct Node *head,int value);                     //Declaration of Deletion after the Node.

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *five;

//<--------------------Allocation Memory in Heap---------------------->    
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    five = (struct Node *)malloc(sizeof(struct Node));

//-----------Insert data in a Node and pointing to the next Node.--------> 
    head->data = 2;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = fourth;

    fourth->data = 5;
    fourth->next = five;

    five->data = 6;
    five->next = NULL;

    printf("\nBefore Insertion element\n");
    Display_Element(head);                                                // Calling Display element function.

    //head = Insert_first(head);                                          // Calling Insert first function.
    //head = Insert_Between(head, 3);                                     // Calling Insert Between function.
    //head = Insert_end(head);                                            // Calling Insert End function.
    head = Insert_AfterNode(head, third);                                 // Calling Insert AfterNode function.
    
    printf("\nAfter Insertion element\n");
    Display_Element(head);                                                // Calling Display element function.

    //head = Delete_first(head);                                           // Calling Deletion first function.
    //head=Delete_Index(head,2);                                           // Calling Deletion Index function.
    //head = Delete_Last(head);                                            // Calling Deletion Last function.
    head = Delete_Value(head,5);                                           // Calling Deletion given Value function.
    
    printf("\nAfter Deletion Element\n");
    Display_Element(head);                                                 // Calling Display element function.
    return 0;
}

void Display_Element(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elements : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
//<----------------------4 function are insert an element at a specified position according to there Function.-------------------->

struct Node *Insert_first(struct Node *head)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = 1;
    ptr->next = head;
    head = ptr;
    return (head);
}

struct Node *Insert_Between(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = 1;
    ptr->next = p->next;
    p->next = ptr;
    return (head);
}

struct Node *Insert_end(struct Node *head)
{
    struct Node *p = head;
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = 1;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

struct Node *Insert_AfterNode(struct Node *head, struct Node *prevNode)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = 1;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

//<------------ 4 function are Deletion an element at a specified position according to there Function.---------------------->

struct Node *Delete_first(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return (head);
}

struct Node *Delete_Index(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return (head);
}

struct Node *Delete_Last(struct Node *head)
{
    struct Node *p=head;
    struct Node *q=head->next;

    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return(head);
}

struct Node *Delete_Value(struct Node *head,int value)
{
    struct Node *p=head;
    struct Node *q=head->next;

    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==value)
    {
        p->next=q->next;
        free(q);
    }
    return(head);
}
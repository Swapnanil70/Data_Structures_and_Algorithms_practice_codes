# include <stdio.h>
# include <stdlib.h>

struct Node {

    int data;
    struct Node *next;

};

void Traversal(struct Node *p)
{
    int i=1;
    while (p !=NULL)
    {
        printf("Element %d",i);
        printf(" = %d\n",p->data);
        p = p->next;
        i++;
    }
}

//case 1 insertion
struct Node * insertAtFirst(struct Node * head, int data)
{

    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    p->next = head;
    p->data = data;
    return p;
}

//case 2 Insertion
struct Node * insertInBetween(struct Node * head, int index, int data)
{
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    int i =  0;
    while(i!=index-1)
    {
        ptr = ptr->next;
        i++;
    }
    p->data = data;
    p->next = ptr->next;
    ptr->next = p; 
    return head;

}

//case 3 Insertion
struct Node * insertAtEnd(struct Node * head, int data)
{
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    struct Node * ptr = head;

    while (ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    p->data = data;
    ptr->next = p;
    p->next = NULL;
    return head;

}

//deletion case 1
struct Node * deleteAtFirst(struct Node * head)
{
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

//deletion case 2
struct Node * deleteInBetween(struct Node * head, int index)
{
    struct Node * p, * q;
    int i = 0;

    p = head;

    while(i <= index-1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

//case 3 deletion
struct Node * deleteAtEnd(struct Node * head)
{
    struct Node * p, *q;
    p = head; 
    q = head->next;

    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

//case 4 deletion
struct Node * deleteWithValue(struct Node * head, int value)
{
    struct Node * p, *q;
    p = head;
    q = head->next;
    
    if (p->data == value)
    {
        head = q;
        free(p);
        return head;
    }
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
    
}


int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    struct Node *sixth;

    //allocate memory for linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 2;
    head->next = second;

    second->data = 33;
    second->next = third;

    third->data = 45;
    third->next = fourth;

    fourth->data = 56;
    fourth->next = fifth;

    fifth->data = 70;
    fifth->next = sixth;

    sixth->data = 100;
    sixth->next = NULL;

    //head = insertAtFirst(head, 90);

    //head = insertInBetween(head, 3, 50);

    //head = insertAtEnd(head, 69);

    //head = deleteAtFirst(head);

    //head = deleteInBetween(head, 2);

    //head = deleteAtEnd(head);

    head = deleteWithValue(head, 100); 

    Traversal(head);
  
}
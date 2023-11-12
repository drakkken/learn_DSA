#include <stdio.h>
#include <stdlib.h>
#define max_size 101
struct node
{

    int data;
    struct node *next;
} *first, *second, *third;

// creating a linked list till the size is mentioned
void createNode(int a[], int n)
{
    int i;
    struct node *t, *last;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// creting  a second linked list using a second method
void createNode2(int a2[], int n)
{
    int i;
    struct node *p;
    second = (struct node *)malloc(sizeof(struct node));
    second->data = a2[0];
    second->next = NULL;
    struct node *last, *t;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a2[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// concatinating two linked list
void concate(struct node *p1, struct node *p2)
{
    while (p1->next != NULL)
    {
        p1 = p1->next;
    }
    p1->next = p2;
}

// merging two linked list
void merge(struct node *p1, struct node *p2)
{
    struct node *third, *last;
    if (p1->data < p2->data)
    {
        last = p1;
        third = p1;
        p1 = p1->next;
        last->next = NULL;
    }
    else
    {
        last = p2;
        third = p2;
        p2 = p2->next;
        last->next = NULL;
    }

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            last->next = p1;
            last = p1;
            p1 = p1->next;
            last->next = NULL;
        }
        else
        {
            last->next = p2;
            last = p2;
            p2 = p2->next;
            last->next = NULL;
        }
    }
    /* the if statement is not inside the loop cause when u attacht the next nodes the remaining nodes is already attached to that one so no need to repeat*/
    if (p1)
        last->next = p1;
    if (p2)
        last->next = p2;
}

// function to display the linked list creted usind a normal function
void Display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
}
// recursive display of the linked list using recrsin
void Rdisplay(struct node *p)
{
    printf("%d", p->data);
    Rdisplay(p->next);
}
// to find numnber of nodes in a linked list
int noOfNodes(struct node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
// to enter the element in anywhere inside the list
void insert(struct node *p, int element, int index)
{
    if (index < 0 || index > noOfNodes(p))
        return;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = element;
    if (index == 0)
    {
        new->next = first;
        first = new;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        new->next = p->next;
        p->next = new;
    }
}
// for deleton of a node
int delete(struct node *p, int index)

{
    if (index == 1)
    {
        int x = first->data;
        first = first->next;
        return x;
    }
    else
    {
        struct node *q = NULL;
        int x;
        for (int i = 0; p && i < index - 1; i++)
        {

            q = p;
            p = p->next;
        }
        x = p->data;
        q->next = p->next;
        free(p);
        return x;
    }
}
// for checking if list is sorted
void issorted(struct node *p)
{
    while (p != NULL)
    {
        int x = -65563;
        if (p->data < x)
            return 0;
        else
            x = p->data;
        p = p->next;
    }
    return 1;
}
// for chcking and removing duplicates from linked ist
/*void rmvduplicate(struct node *p)
{

}*/
// for merging two linked lists
void merge(struct node *p)
{
}

void main()
{
    int node_size, a[max_size];
    printf("Enter the size of the nodes you want to create\n");
    scanf("%d", &node_size);
    printf("enter the elements till that size you want inside the node");
    for (int i = 0; i < node_size; i++)
    {
        scanf("%d", &a[i]);
    }
    createNode(a, node_size);
    int length_of_node = noOfNodes(first);
    printf("\n%d\n", length_of_node);
    insert(first, 5, 4);
    delete (first, 2);
    Display(first);
}
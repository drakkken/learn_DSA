#include <stdio.h>
#include <stdlib.h>
#define max_size 101
struct node
{
    int data;
    struct node *next;
} *head;
int length;

void createCircularLinked(int a[], int size)
{
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = head;
    struct node *t;
    struct node *last = head;
    int i;
    for (i = 1; i < size; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void display(struct node *p)
{
    do
    {
        printf("%d", p->data);
        p = p->next;

    } while (p != head);
    printf("\n");
}
// insert function
void insert(struct node *p, int index, int data)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    if (index == 0)
    {
        if (head == NULL)
        {
            t->next = t;
            head = t;
        }
        else
        {
            while (p->next != head)
                p = p->next;
            t->next = head;
            p->next = t;
        }
    }
    else if (index > length)
    {
        printf("error");
        return;
    }

    else
    {

        for (int i = 0; i < index - 1; i++)
            p = p->next;

        t->next = p->next;
        p->next = t;
    }
}
// main funcion
void main()
{
    int size, a[max_size], index, element;
    printf("enter te size of the linked list\n");
    scanf("%d", &size);
    length = size;
    printf("enter the elemnts needed in the cirular linked list\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &a[i]);
    createCircularLinked(a, size);
    display(head);
    printf("enter the ekement you want to insert :\n");
    scanf("%d", &element);
    printf("where do u want to insert ?:\n");
    scanf("%d", &index);
    insert(head, index, element);
    display(head);
}
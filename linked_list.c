#include <stdio.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL, *sorted = NULL, *chead = NULL;

void insert(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        struct node *t = *head;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = temp;
    }
}
void insertc(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    // temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        temp->next = *head;
    }
    else
    {
        struct node *t = *head;
        while (t->next != *head)
        {
            t = t->next;
        }
        t->next = temp;
        temp->next = *head;
    }
}

void displayc(struct node *c)
{
    printf("\n");
    while (c->next != NULL)
    {
        printf("%d\t", c->data);
        c = c->next;
    }
    printf("%d", c->data);
}
void display(struct node *head)
{
    if (head != NULL)
    {
        printf("%d\t", head->data);
        display(head->next);
    }
}

int nodes(struct node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

int sum(struct node *head)
{
    int sum = 0;
    while (head != NULL)
    {
        sum += head->data;
        head = head->next;
    }
    return sum;
}

int max(struct node *h)
{
    int max = -9999;
    while (h != NULL)
    {
        if (h->data > max)
        {
            max = h->data;
        }
        h = h->next;
    }
    return max;
}

void reverse(struct node **head)
{
    struct node *p, *q, *r;
    p = NULL;
    q = *head;
    r = (*head)->next;
    while (r != NULL)
    {
        p = q;
        q = r;
        r = r->next;
        q->next = p;
    }
    *head = q;
}

void sort_For_insertion(struct node *r)
{
    if (sorted == NULL || r->data < sorted->data)
    {
        r->next = sorted;
        sorted = r;
    }
    else
    {
        struct node *t = sorted;
        while (t->next != NULL && t->next->data < r->data)
        {
            r = r->next;
        }
        r->next = t->next;
        t->next = r;
    }
}

void Insertionsort(struct node *head)
{
    while (head != NULL)
    {
        struct node *t = head->next;
        sort_For_insertion(head);
        head = t;
    }
}

void removeDuplicates(struct node *head)
{
    struct node *t = head, *p;
    struct node *j;

    while (t != NULL)
    {
        p = t;
        while (p->next != NULL)
        {
            if ((p->next->data) == t->data)
            {
                j = p->next;
                p->next = p->next->next;
                free(j);
            }
            else
            {
                p = p->next;
            }
        }
        t = t->next;
    }
}

int isLoop(struct node *t)
{
    struct node *p, *q;
    p = q = t;
    do
    {
        p = p->next;
        q = q->next;
        if (q->next != NULL)
            q = q->next;

    } while ((p && q) && p != q);

    return p == q ? 1 : 0;
}

void merge_two(struct node **h, struct node **h2)
{
    struct node *l1 = *h;
    struct node *l2 = *h2;
    struct node *n = NULL, *last;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data < l2->data)
        {
            if (n == NULL)
            {
                n = l1;
                last = n;
            }
            else
            {
                last->next = l1;
                last = l1;
            }
        }
        else if (l2->data < l1->data)
        {
            if (l1->data < l2->data)
            {
                if (n == NULL)
                {
                    n = l1;
                    last = n;
                }
                else
                {
                    last->next = l1;
                    last = l1;
                }
            }
        }
    }
}

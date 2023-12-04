#include <stdio.h>

struct stacks
{
    int top;
    int arr[100];
} stack;

void push(struct stacks *stack, int element)
{
    if (stack->top == 100 - 1)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        stack->top++;
        stack->arr[stack->top] = element;
    }
}
int pop(struct stacks *stack)
{

    if (stack->top == -1)
    {
        printf("STACK EMPTY\n");
        return -1;
    }
    else
    {
        int x = stack->arr[stack->top];
        stack->top--;
        return x;
    }
}
void sortedpush(struct stacks *stack, int element)
{
    if (stack->top == 100 - 1)
    {
        printf("oompiko");
    }
    else if (stack->top != -1 && element < stack->arr[stack->top])
    {
        int temp = pop(stack);
        sortedpush(stack, element);
        push(stack, temp);
    }
    else if (element > stack->arr[stack->top])
    {
        push(stack, element);
    }
}

/*void pop(struct stacks stack)
{

    if (stack->top == -1)
    {
        printf("STACK EMPTY\n");
    }
    else
    {
        int x = stack->arr[stack->top];
        stack->top--;
    }
}*/

void display(struct stacks *stack)
{
    int i = 0;
    for (i = 0; i <= stack->top; i++)
    {
        printf("%d\n", stack->arr[i]);
    }
}
void main()
{
    stack.top = -1;
    push(&stack, 10);
    sortedpush(&stack, 11);
    sortedpush(&stack, 3);
    sortedpush(&stack, 0);
    display(&stack);
}

#include <stdio.h>
// char infix[100], postfix[100];
#include <stdlib.h>
#define MAX_SIZE 101
// stack structure
struct stackArray
{

    int stackarr[MAX_SIZE];
    int top;

} stack, stack2;

// pop
int pop()
{
    if (stack.top == -1)
        printf("stack empty");
    else
        return (stack.stackarr[stack.top--]);
}
// pop2
int pop2()
{
    if (stack2.top == -1)
        printf("stack2 empty");
    else
        return (stack2.stackarr[stack2.top--]);
}
// push for stack2
void push2(int item)
{
    if (stack2.top == MAX_SIZE - 1)
        printf("stack2 full");
    else
        stack2.stackarr[++stack2.top] = item;
}
// push
void push(int item)
{
    if (stack.top == MAX_SIZE - 1)
        printf("stack full");
    else
        stack.stackarr[++stack.top] = item;
}
int isop(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '(' || c == ')')
    {
        return 1;
    }
    else
        return 0;
}

int convert(char *postfix)
{
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (isop(postfix[i]) != 1)
        {
            push(postfix[i] - '0');
            i++;
        }
        else
        {
            char op = postfix[i++];
            int y = pop();
            int x = pop();
            int result;
            switch (op)
            {
            case '+':
                result = x + y;
                break;

            case '-':
                result = x - y;
                break;

            case '/':
                result = x / y;
                break;

            case '*':
                result = x * y;
                break;

            default:
                printf("WRONG INPUT IN POSTFIX\n");

                break;
            }
            push(result);
            // i++;
        }
    }
}

void main()
{
    stack.top = -1;

    printf("Enter and postfix :\n");
    char postfix[100];
    scanf("%s", postfix);
    convert(postfix);
    int a = pop();
    printf("%d", a);
}
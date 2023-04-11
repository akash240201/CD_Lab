#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK 100
#define MAX_EXPR 100

char stack[MAX_STACK];
int top = -1;

char input[MAX_EXPR];
int input_len = 0;
int current_pos = 0;

char operator_table[7][7] = {
    {'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '<', '<', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'},
    {'>', '>', '>', '>', '<', '>', '>'},
    {'<', '<', '<', '<', '<', '=', '0'},
    {'>', '>', '>', '>', '0', '>', '>'},
    {'<', '<', '<', '<', '<', '0', '='}};

typedef struct
{
    int type;
    char value;
} Token;

Token get_token()
{
    Token t;
    if (current_pos == input_len)
    {
        t.type = 0;
        t.value = '$';
        return t;
    }
    char c = input[current_pos++];
    if (isdigit(c))
    {
        t.type = 1;
        t.value = c;
    }
    else
    {
        t.type = 0;
        t.value = c;
    }
    return t;
}

void push(char c)
{
    if (top == MAX_STACK - 1)
    {
        printf("Error: stack overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
    {
        printf("Error: stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

void display()
{
    int i;
    for (i = 0; i <= top; i++)
    {
        printf("%c", stack[i]);
    }
    printf("    ");
    for (i = current_pos; i < input_len; i++)
    {
        printf("%c", input[i]);
    }
    printf("\n");
}

void parse()
{
    Token t = get_token();
    push('$');
    display();
    while (top >= 0)
    {
        char c = stack[top];
        if (isdigit(c))
        {
            t = get_token();
            if (t.type == 0)
            {
                printf("Error: invalid input token\n");
                exit(1);
            }
            push(t.value);
            display();
        }
        else
        {
            int r = strchr("+-*/()$", c) - strchr("+-*/()$", '$');
            int c = strchr("+-*/()$", t.value) - strchr("+-*/()$", '$');
            char op = operator_table[r][c];
            if (op == '>')
            {
                char b = pop();
                char a = pop();
                char p = pop();
                if (p != '(')
                {
                    printf("Error: invalid input\n");
                    exit(1);
                }
                push(a);
                push(b);
                display();
            }
            else if (op == '<' || op == '=')
            {
                push(t.value);
                display();
                t = get_token();
            }
            else
            {
                printf("Error: invalid operator precedence\n");
                exit(1);
            }
        }
    }
}

int main()
{
    printf("Enter the input expression: ");
    scanf("%s", input);
    input_len = strlen(input);
    strcat(input, "$");
    parse();
    return 0;
}
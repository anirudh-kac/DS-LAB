#include <stdio.h>
int top = -1;
char stack[20];
void push(char);
char pop();
int stpri(char ch);
int inpri(char ch);
void convert(char infix[],char postfix[]);

int main()
{
    char infix[20],postfix[20];
    push('#');
    printf("Enter the infix expression: \n");
    scanf("%s",infix);
    convert(infix,postfix);
    printf("The postfix expression is : %s\n",postfix);
    return 0;
}

void push(char ch)
{
    stack[++top]=ch;
}

char pop()
{
    return stack[top--];
}

int stpri(char ch)
{
    switch(ch)
    {
        case '#':
        case '(': return 0;
        case '+':
        case '-':return 2;
        case '*':
        case '%':
        case '/':return 4;
        case '^':return 5;
    }
    return 0;
}

int inpri(char ch)
{
    switch (ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/':
        case '%': return 3;
        case '^':return 6;
    }
    return 0;
}

void convert(char in[],char post[])
{
    int i,j=0;
    char ch;
    for(i=0;in[i];i++)
    {
        ch=in[i];
        switch (ch)
        {
            case '(': push(ch);
                        break;
            case ')':
                    while(stack[top]!='(')
                        post[j++]=pop();
                    pop();
                    break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                        while(stpri(stack[top])>inpri(ch))
                            post[j++]=pop();
                        push(ch);
                        break;
            default: post[j++] = ch;
        }
    }
    while(stack[top]!='#')
        post[j++] = pop();
    post[j]= '\0';
}
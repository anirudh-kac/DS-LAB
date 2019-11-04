#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int top =-1;

int overflow();
int underflow();
void push(int *s,int ele);
int pop(int *s);
void display(int *s);
int palin(char *pat,int *s);

int main()
{
    int stack[MAX] , ch, i,j,ele,p;
    char str[10];
    while(1)
    {
        printf("\n 1. Push \n 2. Pop \n 3. Check Palindrome \n 4. Display \n 5. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the element to be inserted: \n");
                scanf("%d",&ele);
                push(stack,ele);
                break;
            case 2:
                ele = pop(stack);
                if(ele!=0)
                    printf("The deleted element is %d",ele);
                break;
            case 3:
                printf("Enter the string : \n");
                // fflush(stdin);
                // gets(str);
                scanf("%s",str);
                p = palin(str,stack);
                if(p)
                    printf("Given String is Palindrome\n");
                else 
                    printf("Not Palindrome \n");
                break;
            case 4 :
                display(stack);
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}


int overflow()
{
    if(top == MAX-1)
        return 1;
    return 0;
}

int underflow()
{
    if(top== -1)
        return 1;
    return 0;
}

void push(int *s, int ele)
{
    if(!overflow())
        s[++top]=ele;
    else 
        printf("Stack Overflow \n");
}

int pop(int *s)
{
    if(!underflow())
        return (s[top--]);
    else
    {
        printf("Stack Underflow");
        return 0;
    }
    
}

void display(int *s)
{
    int i;
    if(underflow())
    {
        printf("Stack Underflow\n");
        return;
    }
    else
    {
        printf("Contents of the stack are : \n");
        for(i=0;i<=top;i++)
        {
            printf("%d\t",s[i]);
        }
        return;
    }
    
}

int palin(char * pat ,int *s)
{
    int i , top = -1;

    for(i=0;pat[i]!='\0';i++)
        push(s,pat[i]-'0');

    for(i=0;pat[i]!='\0';i++)
    {
        if(pat[i]!= (pop(s)+ '0'))
            return 0;
    }
    return 1;
}
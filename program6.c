#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int CQ[MAX];
int f=-1,r=-1;

void CQinsert(int elem)
{
    if(Qfull())
        printf("\n Queue Overflow\n");
    else
    {
        if(f==-1)
            f=0;
        r=(r+1)%MAX;
        CQ[r]=elem;
    }
}

int CQdelete()
{
    int elem;
    if(Qempty())
    {
        printf("\n Underflow \n");
        return -1;
    }
    else
    {
        elem = CQ[f];
        if(f==r)
        {
            f=-1;
            r=-1;
        }
        else
        {
            f=(f+1)%MAX;
        }
        
    }
    return elem;
    
}

int Qfull()
{
    if(f==0 && r==MAX-1)
        return 1;
    return 0;
}

int Qempty()
{
    if(f==-1)
        return 1;
    return 0;
}

void display()
{
    int i;
    if(Qempty())
        printf("Queue Empty\n");
    else
    {
        printf("Front [%d] -->",f);
        for(i=f;i!=r;i=(i+1)%MAX)
            printf("%d\t",CQ[i]);
        printf("<--[%d] Rear",r);
    }
    
}

int main()
{
    int opn;
    int elem,ch;
    while(1)
    {
        printf("\nEnter your choice :\n 1. Insert \n 2. Delete \n 3. Display \n 4. Exit\n");
        scanf("%d",&opn);
        switch(opn)
        {
            case 1:
                printf("Enter element to be inserted: \n");
                scanf("%d",&elem);
                //ch=getchar();
                CQinsert(elem);
                break;
            case 2:
                elem = CQdelete();
                if(elem!=-1)
                    printf("The deleted element is %d \n",elem);
                break;
            case 3:
                printf("The circular Queue is : \n");
                display();
                break;
            case 4: 
                exit(0);
        }
    }
    return 0;
}
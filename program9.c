#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int coeff;
    int exp[3];
    struct node *next;
};


//insert rear
struct node* add_term(struct node* p,int coeff,int i,int j,int k)
{
    struct node* temp =malloc(sizeof(struct node));
    struct node* temp1 = p->next;//
    temp->coeff=coeff;
    temp->exp[0]=i;
    temp->exp[1]=j;
    temp->exp[2]=k;
    while(temp1->next!=p)
        temp1=temp1->next;
    temp1->next=temp;
    temp->next=p;
    return p;
}

struct node* mkheader()
{
    struct node *p = malloc(sizeof(struct node));
    p->coeff=-1;
    p->exp[0]=-1;
    p->exp[1]=-1;
    p->exp[2]=-1;
    p->next=p;
    return p;
}

double evaluate(struct node*p , int i,int j,int k)
{
    struct node* po = p->next;
    double sum=0;
    while(po!=p)
    {
        sum+= po->coeff * pow(i,po->exp[0]) * pow(j,po->exp[1]) * pow(k,po->exp[2]);
        po=po->next;
    }
    return sum;
}


//just iterating to display
void print_poly(struct node *p)
{
    struct node* po =p->next;
    while(po!=p)
    {
        printf("%dx^%dy^%dz^%d",po->coeff,po->exp[0],po->exp[1],po->exp[2]);
        if(po->next!=p)
            printf(" + ");
        po=po->next;
    }
    printf("\n");
}

//calling add term in a loop
void read(struct node*t1,int n)
{
    int i;
    struct node* temp =malloc(sizeof(struct node));
    for(i=0;i<n;i++)
    {
        printf("Enter values of coeffieient and exponents of x,y,z");
        scanf("%d %d %d %d",&temp->coeff,&temp->exp[0],&temp->exp[1],&temp->exp[2]);
        t1 = add_term(t1,temp->coeff,temp->exp[0],temp->exp[1],temp->exp[2]);
    }
    print_poly(t1);
}

struct node* add(struct node *p1,struct node* p2)
{
    struct node* temp = mkheader();
    struct node* t1 = p1->next,*t3=p1->next;
    struct node* t2 = p2->next,*t4= p2->next;
    int i,flag;
    while(t1!=p1)
    {
        t2=p2->next;
        while(t2!=p2)
        {
            flag=0;
            for(i=0;i<3;i++)
            {
                if(t1->exp[i]!=t2->exp[i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                temp = add_term(temp,t1->coeff+t2->coeff,t1->exp[0],t1->exp[1],t1->exp[2]);
                break;
            }
            t2 = t2->next;
        }
        if(flag==1)
        {
            temp = add_term(temp,t1->coeff,t1->exp[0],t1->exp[1],t1->exp[2]);
        }
        t1=t1->next;////
    }

    while(t4!=p2)
    {
        t3=p1->next;
        while(t3!=p1)
        {
            flag=0;
            for(i=0;i<3;i++)
            {
                if(t3->exp[i]!=t4->exp[i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                break;
            t3=t3->next;
        }
        if(flag==1)
        {
            temp = add_term(temp,t4->coeff,t4->exp[0],t4->exp[1],t4->exp[2]);
        }
        t4=t4->next; ////
    }
    return temp;
}

int main()
{
    int n,x,y,z,ch,i,coeff;
    struct node* polysum;
    struct node* p =mkheader();
    struct node* poly2=mkheader();
    while(1)
    {
        printf("\n 1.Evaluate Polynomial \n 2. Add \n 3. Exit\n Enter your choice \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter no. of terms\n");
            scanf("%d",&n);
            read(p,n);
            printf("Enter values of x,y,x \n");
            scanf("%d%d%d",&x,&y,&z);
            printf("%f\n",evaluate(p,x,y,z));
            break;

            case 2:
            printf("Enter the terms in polynomial \n");
            scanf("%d",&n);
            read(poly2,n);
            polysum = add(p,poly2);
            print_poly(polysum);
            break;

            case 3:
            exit(0);

        }
    }
    return 0;
}
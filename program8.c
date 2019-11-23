#include <stdio.h>
#include <stdlib.h>

struct node
{
    char SSN[10];
    char name[10];
    char branch[10];
    char des[10];
    char sal[10];
    char phone[10];
    struct node* llink;
    struct node* rlink;
};

struct node* head= NULL;

struct node* createnode()
{
    struct node* temp;
    temp =malloc(sizeof(struct node));
    printf("Enter SSN: \n");
    scanf("%s",temp->SSN);
    printf("Enter Name: \n");
    scanf("%s",temp->name);
    printf("Enter Branch: \n");
    scanf("%s",temp->branch);
    printf("Enter Designation: \n");
    scanf("%s",temp->des);
    printf("Enter Salary: \n");
    scanf("%s",temp->sal);
    printf("Enter phone: \n");
    scanf("%s",temp->phone);
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}


void insertfront()
{
    struct node * DLL = NULL;
    DLL = createnode();
    if(head!=NULL)
    {
        DLL->rlink = head;
        head->llink  = DLL;
    }
    head = DLL;
}

void delfront()
{
    struct node* DLL = head;
    printf("The deleted node is : \n");
    printf("SSN = %s\n",DLL->SSN);
    printf("Name = %s\n",DLL->name);
    printf("Sal = %s\n",DLL->sal);
    printf("Phone = %s\n",DLL->phone);
    head = DLL->rlink;
    head->llink = NULL;
    free(DLL);
}

void insertEnd()
{
    struct node * DLL, *temp =head,*ptr;
    DLL = createnode();
    if(head==NULL)
        head=DLL;
    else
    {
        while(temp->rlink!=NULL)
        {
            ptr=temp;
            temp=temp->rlink;
        }
        temp->rlink = DLL;
        DLL->llink = temp;

    }
}

void deleteEnd()
{
    struct node* temp =head;
    struct node *t;
    if(head==NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        while(temp->rlink!=NULL)
        {
            t=temp;
            temp=temp->rlink;
        }
        printf("The deleted node is : \n");
        printf("SSN = %s\t",temp->SSN);
        printf("Name = %s\t",temp->name);
        printf("Branch = %s\t",temp->branch);
        printf("Phone = %s\t",temp->phone);
        free(t->rlink);
        t->rlink = NULL;

    }
    
}

void create()
{
    int n,i;
    printf("Enter number of students : \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        insertEnd();
    }
}

void display()
{
    int c=0;
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("\n%s\t",temp->SSN);
        printf("%s\t",temp->name);
        printf("%s\t",temp->branch);
        printf("%s\t",temp->des);
        printf("%s\t",temp->sal);
        temp=temp->rlink;
        c++;
    }
    printf("Number of nodes is : %d",c);
}

void dequeue()
{
    int choice;
    printf("\n 1. Insert at front \n 2. Insert at rear \n 3. Delete from front \n 4. Delete fron rear\n 5.Display \n Enter your choice : \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 :
        printf("Enter details to be inserted : \n");
        insertfront();
        break;
        case 2:
        printf("Enter details to be inserted \n");
        insertEnd();
        break;
        case 3:
        printf("The deleted node is : \n");
        delfront();
        break;
        case 4:
        printf("The delete node is : \n");
        deleteEnd();
        break;
        case 5:
        display();
        break;
    }
}

int main()
{
    int ch1,ch2,ch3;
    while(1)
    {
        printf("Enter your chooice : \n 1.Create \n 2. Display \n 3. Insert and delete at end \n 4. Insert and delete from front \n 5. DLL as Dequeue\n 6. Exit \n");
        scanf("%d",&ch1);
        switch(ch1)
        {
            case 1:
            create();
            break;
            case 2:
            display();
            break;
            case 3:
            printf("Enter your choice : \n 1 . Insert \n 2. Delete \n");
            scanf("%d",&ch2);
            if(ch2==1)
                insertEnd();
            else
                deleteEnd();
            break;
            case 4:
            printf("Enter your choice : \n 1. Insert \n 2. Delete\n");
            scanf("%d",&ch3);
            if(ch3==1)
                insertfront();
            else
                delfront();
            break;
            case 5:
            dequeue();
            break;
            case 6:
            exit(0);
        }
    }
    return 0;
}
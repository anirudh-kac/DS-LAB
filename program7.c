#include <stdio.h>
#include <stdlib.h>
struct node
{
    char USN[3];
    char name[10];
    char branch[4];
    char sem[3];
    char phone[10];
    struct node* link;
};

struct node* head = NULL;

struct node* createnode()
{
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter the USN\n");
    scanf("%s",temp->USN);
    printf("\nEnter the Name\n");
    scanf("%s",temp->name);
    printf("\nEnter the Branch\n");
    scanf("%s",temp->branch);
    printf("\nEnter the sem\n");
    scanf("%s",temp->sem);
    printf("\nEnter the phone number \n");
    scanf("%s",temp->phone);
    temp->link = NULL;
    return temp;
}

void insertFront()
{
    struct node* SLL = NULL;
    SLL = createnode();
    if(head!=NULL)
        SLL->link=head;
    head = SLL;
}

void delFront()
{
    struct node * SLL = head;
    printf("\n The deleted node is : \n");
    printf("USN = %s\n",SLL->USN);
    printf("Name = %s\n",SLL->name);
    printf("Branch = %s\n",SLL->branch);
    printf("Sem = %s\n",SLL->sem);
    printf("Phone = %s\n",SLL->phone);
    head= SLL->link;
    free(SLL);
}

void insertEnd()
{
    struct node *SLL,*temp=head;
    SLL=createnode();
    if(head == NULL)
        head=SLL;
    else
    {
        while(temp->link!=NULL)
            temp = temp->link;
        temp->link=SLL;
    }
    
}

void deleteEnd()
{
    struct node * temp =head;
    struct node* t;
    if(head==NULL)
        printf("Linked List is Empty\n");
    else if(head->link==NULL)
    {
        temp=head;
        printf("The deleted node is \n");
        printf("USN = %s\n",temp->USN);
        printf("Name = %s\n",temp->name);
        printf("Sem = %s\n",temp->sem);
        printf("Branch = %s\n",temp->branch);
        printf("Phone = %s\n",temp->phone);
        free(temp);
        head=NULL;
    }
    else
    {
        while(temp->link!=NULL)
        {
            t = temp;
            temp= temp->link;
        }
        printf("The deleted node is \n");
        printf("USN = %s\n",temp->USN);
        printf("Name = %s\n",temp->name);
        printf("Sem = %s\n",temp->sem);
        printf("Branch = %s\n",temp->branch);
        printf("Phone = %s\n",temp->phone);
        free(t->link);
        t->link = NULL;
    }

}

void create()
{
    int n,i;
    printf("Enter the number of students : \n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        insertFront();
    }
}

void display()
{
    int c=0;
    struct node * temp=head;
    while(temp!=NULL)
    {
        printf("%s\t",temp->USN);
        printf("%s\t",temp->name);
        printf("%s\t",temp->sem);
        printf("%s\t",temp->branch);
        printf("%s\n",temp->phone);
        temp=temp->link;
        c++;
    }
    printf("\n The number of node is %d\n",c);
}


void stack()
{
    int choice;
    printf("\n 1. Push \n 2. Pop \n 3. Display \n Enter your choice \n");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
        printf("Enter details to push onto the stack \n");
        insertFront();
        break;
        case 2:
        printf("The popped node is : \n");
        delFront();
        break;
        case 3:
        printf("The stack is : \n");
        display();
        break;
    }
}

void queue()
{
    int choice;
    printf("\n 1. Insert \n 2. Delete \n 3.Display\n Enter your choice : \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("Enter element to be insetred in the queue\n");
        insertEnd();
        break;
        case 2:
        printf("The deleted node is : \n");
        delFront();
        break;
        case 3:
        printf("Contents of the Queue are : \n");
        display();
        break;
    }
}

int main()
{
    int ch1,ch2,ch3;
    while(1)
    {
        printf("\n Enter your choice : \n 1. Create \n 2. Display and count \n 3. Insert and Delete at End \n 4. INsert and delete at Front \n 5. SLL as stack \n 6. SLL as Queue\n7. Exit\n");
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
            printf("Enter your choice: \n 1.Insert \n 2. Delete\n ");
            scanf("%d",&ch2);
            if(ch2==1)
            {
                insertEnd();
            }else
            {
                deleteEnd();
            }
            break;
            case 4:
            printf("Enter your choice : \n 1. Insert \n 2. Delete \n");
            scanf("%d",&ch3);
            if(ch3==1)
            {
                insertFront();
            }
            else
            {
                delFront();
            }
            break;
            case 5:
            stack();
            break;
            case 6:
            queue();
            break;
            case 7 : exit(0);
            
        }

    }
    return 0;
}
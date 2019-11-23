#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int item)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}

struct node* insert(struct node* node,int key)
{
    if(node==NULL) return newNode(key);
    if(key<node->data)
        node->left = insert(node->left,key);
    if(key>node->data)
        node->right = insert(node->right,key);
    return node;
}

int search(struct node* root,int key)
{
    if(root==NULL)
        return -1;
    if(root->data == key)
        return 1;
    if(root->data <key)
        return search(root->right,key);
    return search(root->left,key);
}

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node * root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

int main()
{
    int n,i,ch,ch1,key,pos;
    struct node* root = NULL;
    while(1)
    {
        printf("Enter your choice \n 1. Create BST \n 2. Traversal \n 3. Search for key \n 4.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter number of nodes : \n");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                printf("Enter element to be inserted \n");
                scanf("%d",&key);
                root = insert(root,key);
            }
            break;
            case 2:
            printf("Enter your choice : \n 1. Preorder \n 2. Inorder \n 3. Postorder \n");
            scanf("%d",&ch1);
            if(ch1==1)
                preorder(root);
            else if(ch1==2)
                inorder(root);
            else
                postorder(root);
            break;
            case 3:
            printf("Enter key to be searched \n");
            scanf("%d",&key);
            pos = search(root,key);
            if(pos==-1)
                printf("\n Key not found \n");
            else
                printf("Key is found\n");
            break;
            case 4:
            exit(0);
        }
    }
    return 0;
}
#include <stdio.h>

void move(int n , char source , char dest , char spare);

int main()
{
    int n;
    printf("Enter the number of disks : \n");
    scanf("%d",&n);
    move(n,'A','C','B');
    return 0;
}

void move(int n, char src, char des, char spare)
{
    if(n==1)
    {
        printf("Move from %c to %c\n",src,des);
    }
    else
    {
        move(n-1,src,spare,des);
        move(1,src,des,spare);
        move(n-1,spare,des,src);
    }
    
}
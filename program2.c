#include <stdio.h>

void read(char *s);
void strcopy(char *s1,char *s2);
int match_replace(char *str,char *pat,char *rep);

int main()
{
    char str[100],pat[100],rep[20];
    int flag=0;
    printf("Enter the string:\n");
    read(str);
    printf("Enter the pattern : \n");
    read(pat);
    printf("Enter the replacement: \n");
    read(rep);
    flag = match_replace(str,pat,rep);
    if(flag==1)
    {
        printf("The string is found %s\n",str);
    }
    else
    {
        printf("The string is not found\n");
    }
    return 0;
}

void read(char *s)
{
    //scanf("%s",s);
    gets(s);
}

void strcopy(char *s1,char *s2)
{
    int i;
    for(i=0;s2[i]!='\0';i++)
    {
        s1[i]=s2[i];
    }
}

int match_replace(char *str,char *pat,char *rep)
{
    char ans[100];
    int i=0,m=0,c=0,j=0,flag=0,k;
    while(str[c]!='\0')
    {
        if(str[m]==pat[i])
        {
            i++,m++;
            if(pat[i]=='\0')
            {
                flag=1;
                for(k=0;rep[k]!='\0';k++,j++)
                {
                    ans[j]=rep[k];
                }
                i=0;
                c=m;
            }
        }
        else
        {
            ans[j]=str[c];
            j++,c++;
            m=c;
            i=0;
        }
        
    }
    ans[j]='\0';
    strcopy(str,ans);
    return flag;
}
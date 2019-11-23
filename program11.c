#include <stdio.h>
#include <stdlib.h>

int a[10][10],n,m,i,j,source,s[10]={0},b[10]={0},vis[10]={0};

void create()
{
    printf("Enter number of vertices : \n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }
}

void bfs()
{
    int q[10],u,front=0,rear=-1;
    printf("Enter source vertex \n");
    scanf("%d",&source);
    q[++rear]=source;
    vis[source]=1;
    printf("The reachable vertices are : \n");
    while(front<=rear)
    {
        u = q[front++];
        for(j=1;j<=n;j++)
        {
            if(a[u][j]==1 && vis[j]==0)
            {
                q[++rear]=j;
                vis[j]=1;
                printf("\t %d",j);
            }
        }
    }
}

void dfs(int source)
{
    int v;
    b[source]=1;
    for(v=1;v<=n;v++)
    {
        if(a[source][v]==1 && b[v]==0)
        {
            printf("\n%d->%d",source,v);
            dfs(v);
        }
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n 1. Create Graph \n 2. BFS \n 3. Check Graph Connectivity \n 4. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :
            create();
            break;
            case 2:
            bfs();
            for(i=1;i<=n;i++)
            {
                if(vis[i]==0)
                    printf("Vertex is not reachable : %d",i);
            }
            break;
            case 3:
            printf("Enter the source vertex to find connectivity : \n");
            scanf("%d",&source);
            m=1;
            dfs(source);
            for(i=1;i<=n;i++)
            {
                if(b[i]==0)
                    m=0;
            }
            if(m)
                printf("Graph is connected \n");
            break;
            case 4:
            exit(0);
        }
    }
    return 0;
}
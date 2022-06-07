// #include<stdio.h>
// #define MAX 30

// typedef struct edge
// {
//  int u,v,w;
// }edge;

// typedef struct edgelist
// {
//  edge data[MAX];
//  int n;
// }edgelist;

// edgelist elist;

// int G[MAX][MAX],n;
// edgelist spanlist;

// void kruskal();
// int find(int belongs[],int vertexno);
// void union1(int belongs[],int c1,int c2);
// void sort();
// void print();

// void main()
// {
//  int i,j,total_cost;
//  printf("\nEnter number of vertices:");
//  scanf("%d",&n);
//  printf("\nEnter the adjacency matrix:\n");
//  for(i=0;i<n;i++)
//  for(j=0;j<n;j++)
//  scanf("%d",&G[i][j]);
//  kruskal();
//  print();
// }

// void kruskal()
// {
//  int belongs[MAX],i,j,cno1,cno2;
//  elist.n=0;

//  for(i=1;i<n;i++)
//  for(j=0;j<i;j++)
//  {
//  if(G[i][j]!=0)
//  {
//  elist.data[elist.n].u=i;
//  elist.data[elist.n].v=j;
//  elist.data[elist.n].w=G[i][j];
//  elist.n++;
//  }
//  }
//  sort();
//  for(i=0;i<n;i++)
//  belongs[i]=i;
//  spanlist.n=0;
//  for(i=0;i<elist.n;i++)
//  {
//  cno1=find(belongs,elist.data[i].u);
//  cno2=find(belongs,elist.data[i].v);
//  if(cno1!=cno2)
//  {
//  spanlist.data[spanlist.n]=elist.data[i];
//  spanlist.n=spanlist.n+1;
//  union1(belongs,cno1,cno2);
//  }
//  }
// }

// int find(int belongs[],int vertexno)
// {
//  return(belongs[vertexno]);
// }

// void union1(int belongs[],int c1,int c2)
// {
//  int i;
//  for(i=0;i<n;i++)
//  if(belongs[i]==c2)
//  belongs[i]=c1;
// }

// void sort()
// {
//  int i,j;
//  edge temp;
//  for(i=1;i<elist.n;i++)
//  for(j=0;j<elist.n-1;j++)
//  if(elist.data[j].w>elist.data[j+1].w)
//  {
//  temp=elist.data[j];
//  elist.data[j]=elist.data[j+1];
//  elist.data[j+1]=temp;
//  }
// }

// void print()
// {
//  int i,cost=0;
//  for(i=0;i<spanlist.n;i++)
//  {
//  printf("\n%d\t%d\t%d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
//  cost=cost+spanlist.data[i].w;
//  }
//  printf("\n\nCost of the spanning tree=%d",cost);
// } 

#include <stdio.h>
int graph[100][100];
int set[100];
int parent[100];
int ver;
int edge_no = 0;
struct edge
{
    int pt1;
    int pt2;
    int wt;
    int sol;
};
struct edge edges[100];
void edgesCalulate()
{
    int count = 0;
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (graph[i][j] != 0)
            {
                edges[count].pt1 = i;
                edges[count].pt2 = j;
                edges[count].wt = graph[i][j];
                edges[count].sol = 0;
                count++;
            }
        }
    }
    edge_no = count;
}
void edgesSort()
{
    struct edge temp;
    for (int i = 0; i < edge_no; i++)
    {
        for (int j = 0; j < edge_no - 1; j++)
        {
            if (edges[j].wt > edges[j + 1].wt)
            {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int main()
{
    printf("Enter Total Number Of Vertices In Graph: ");
    scanf("%d",&ver);
    printf("Enter Distances For each Vertex-\n");
    for (int i = 0; i < ver; i++)
    {
        printf("From Vertex %c : ",i + 97);
        for(int j=0;j<ver;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    edgesCalulate();
    edgesSort();
    for (int i = 0; i < ver; i++)
    {
        set[i] = i;
    }

    for (int i = 0; i < edge_no; i++)
    {
        if (set[edges[i].pt1] != set[edges[i].pt2])
        {
            edges[i].sol = 1;
            int temp;
            temp = set[edges[i].pt1];
            for (int j = 0; j < edge_no; j++)
            {
                if (set[j] == temp)
                    set[j] = set[edges[i].pt2];
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < edge_no; i++)
    {
        if (edges[i].sol)
        {
            sum = sum + edges[i].wt;
            printf(" wt- %d ", edges[i].wt);
            printf(" ( %c , %c ) \n", edges[i].pt1 + 97, edges[i].pt2 + 97);
        }
    }
    printf("Minimum Cost Of Spanning Tree: %d ", sum);
    return 0;
}

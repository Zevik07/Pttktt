#include <stdio.h>
//Do thi
typedef struct {
    int A[100][100];
    int n;
} Graph;
void init_graph(Graph *G,int n)
{
	int i,j;
	G->n=n;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
			G->A[i][j]=0;
	}
}
void add_edge(Graph *G,int x,int y,int w)
{
	G->A[x][y]=w;
	G->A[y][x]=w;
}
int min(int a, int b)
{
	return a>b?b:a;
}
int c(Graph *G, int d[],int i, int j)
{
	int k;
	int min2=9999999;
	if (G->A[i][j]!=0) return G->A[i][j];
	if (i==j){
		G->A[i][j]=0;
		return 0;
	}
	else {
		for(k=i;k<j;k++)
		{
			min2=min(c(G,d,i,k)+c(G,d,k+1,j)+d[i-1]*d[k]*d[j],min2);
		}
		add_edge(G,i,j,min2);
		return min2;
	}
}
int main()
{
	Graph G;
	int n;
	scanf("%d",&n);
	init_graph(&G,n);
	int d[n+1];
	for (int i=0;i<n+1;i++)
	{
		scanf("%d",&d[i]);
	}
	printf("%d",c(&G,d,1,n));
}

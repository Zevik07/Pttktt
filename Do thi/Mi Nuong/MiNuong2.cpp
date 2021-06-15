#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
typedef struct
{
	int u,v;
}Edge;
int main()
{
	int n;
	cin>>n;
	Edge* edge=(Edge*)malloc(n*sizeof(Edge));
	for (int i=0;i<n-1;i++)
	{
		cin>>edge[i].u>>edge[i].v;
	}
	int k;
	cin>>k;
	int *K=new int[k];
	for (int i=0;i<k;i++)
	{
		cin>>K[i];
	}
	sort(K,K+k);
	int *f=new int[n+1];
	for (int i=0;i<=n;i++)
	{
		f[i]=n-1;
	}
	f[1]=0;
	for (int i=0;i<n-1;i++)
	{
		int u=edge[i].u;
		int v=edge[i].v;
		if (f[u]<f[v]) f[v]=f[v]<f[u]+1?f[v]:f[u]+1;
		else if (f[v]>f[u]) f[u]=f[u]<f[v]+1?f[u]:f[v]+1;
	}
	int min_path=n-1;
	int u;
	for (int i=0;i<k;i++)
	{
		u=K[i];
		min_path=min_path<f[u]?min_path:f[u];
	}
	for (int i=0;i<k;i++)
	{
		u=K[i];
		if (f[u]==min_path) break;
	}
	cout<<u;
	delete[] f;
	delete[] K;
}

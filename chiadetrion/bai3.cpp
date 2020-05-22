#include <stdio.h>
#include <stdlib.h>
int search2(long long *a,long long key, int start, int end)
{
	int i=(start+end)/2;
	while(start!=i and i!=end)
	{
		if (*(a+i)>=key) end=i;
		else start=i;
		i=(start+end)/2;
	}
	for (i=start;i<=end;i++)
	{
		if (*(a+i)>=key) break;
	}
	return i+1;
}
int main()
{
	int n,q;
	int *a;
	long long *temp;
	long long x;
	scanf("%d",&n);
	scanf("%d",&q);
	a=(int*)malloc(n*sizeof(int));
	temp=(long long*)malloc(n*sizeof(long long));
	for(int i=0;i<n;i++)
	{
		scanf("%d",&*(a+i));
	}
	*temp=*a;
	for(int i=1;i<n;i++)
	{
		*(temp+i)=(long long)*(a+i)+*(temp+(i-1));
	}
	for(int i=0;i<q;i++)
	{
		scanf("%lld",&x);
		printf("%d\n",search2(temp,x,0,n-1));
	}
}

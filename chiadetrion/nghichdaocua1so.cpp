#include <stdio.h>
#include <math.h>
long long modulok(int x, int n, int m)
{
	if (n==0) return 1;
	else 
	{
		int temp=modulok(x,n/2,m);
		if (n%2==0) return ((long long)temp*temp)%m;
		else return ((((long long)temp*temp)%m)*x)%m;
		}
}
int main()
{
	int a,p;
	scanf("%d %d",&a,&p);
	printf("%lld",modulok(a,p-2,p));
}

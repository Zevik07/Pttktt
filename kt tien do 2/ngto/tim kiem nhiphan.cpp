#include <stdio.h>
int binarySearch(int a[],int n,int start,int end)
{
	int i=(start+end)/2;
	while (start!=i and i!=end)
	{
		if (a[i]>=n) end=i;
		else start=i;
		i=(start+end)/2;
	}
	for (i=start;i<=end;i++)
		if (a[i]>=n) break;
	return i;
}
int main()
{
	int a[]={5,6,7,10,8};
	printf("%d",binarySearch(a,99,0,4));
}

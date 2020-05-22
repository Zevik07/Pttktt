#include<stdio.h>
int sumArray(int a[],int n)
{
	if (n==1) return a[0];
	else {
		return a[n-1]+sumArray(a,n-1);
	}
}
int main()
{
	int arraysize;
	scanf("%d",&arraysize);
	int a[arraysize];
	for (int i=0;i<arraysize;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Tong mang la %d",sumArray(a,arraysize));
}

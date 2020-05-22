#include<stdio.h>
int main()
{
	int size;
	scanf("%d",&size);
	int a[size];
	for(int i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	int tong=a[0];
	int temp=0;
	//thuat toan brute force tim day con co tong lon nhat
	for (int i=0;i<size;i++)
	{
		temp=a[i];
		for (int j=i;j<size;j++)
		{
			if(j!=i) temp+=a[j];
		}
		if (temp>tong) tong=temp;
	}
	printf("Day con lon nhat la: %d",tong);
}

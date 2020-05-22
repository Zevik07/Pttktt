#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
int maxsumLR(int a[], int l, int r, int LR)
{
	int sum=0;
	int maxsum=-100000;
//	if (LR==0)
		for (int i=r;i>=l;i--)
			{
				sum+=a[i];
				if (sum>maxsum) maxsum=sum;
			}
//	if (LR==1) 
//		for (int i=l;i<=r;i++)
//			{
//				sum+=a[i];
//				if (sum>maxsum) maxsum=sum;
//			}
	return maxsum;
}
int max_sum_dequi(int a[],int l, int r)
{
	if (l==r) return a[l];
	int m=(l+r)/2;
	int max_sumL=max_sum_dequi(a,l,m);
	int max_sumR=max_sum_dequi(a,m+1,r);
	int max_sumM=maxsumLR(a,l,m,0)+maxsumLR(a,m+1,r,1);
	int tongmax=max_sumM;
	if (max_sumL>tongmax) tongmax=max_sumL;
	if (max_sumR>tongmax) tongmax=max_sumR;
	return tongmax;
}
int max_sum(int a[],int N)
{
	return max_sum_dequi(a,1,N); 
}
int main(){
	int n=5;
	int a[] = {0,-2,3,7,-2,9};
	printf("%d ",max_sum(a,n));
}

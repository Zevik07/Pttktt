#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

int maxsumLR(int a[], int l, int r, int LR /* doi so nay de phan biet day con trai hay phai*/)
{
	int sum=0;
	int maxsum=-1001;
	if (LR==0)
		for (int i=r;i>=l;i--)
			{
				sum+=a[i];
				if (sum>maxsum) maxsum=sum;
			}
	if (LR==1) 
		for (int i=l;i<=r;i++)
			{
				sum+=a[i];
				if (sum>maxsum) maxsum=sum;
			}
	return maxsum;
}
int max_sum_dequi(int a[],int l, int r)
{
	if (l==r) return a[l];
	int m=(l+r)/2;
	int max_sumL=max_sum_dequi(a,l,m);
	int max_sumR=max_sum_dequi(a,m+1,r);
	int max_sumM=maxsumLR(a,l,m,0)+maxsumLR(a,m+1,r,1);
	//so sanh 3 tong vua tim duoc
	int tongmax=max_sumM;
	if (max_sumL>tongmax) tongmax=max_sumL;
	if (max_sumR>tongmax) tongmax=max_sumR;
	return tongmax;
}
int max_sum(int a[],int N)
{
	return max_sum_dequi(a,0,N-1); 
}

int main() {
    int n = 5;
	int A[]={2,5,2,1,9};	
	cout << max_sum(A, n) << endl;  
    return 0;
}

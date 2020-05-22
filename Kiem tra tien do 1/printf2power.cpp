//Kiem tra tien do 1
#include <iostream>
#include <math.h>
using namespace std;
int getMax(int A[],int n)
{
	if (n==1) return A[0];
	else {
		int max=getMax(A,n-1);
		return max>A[n-1]?max:A[n-1];
	}
}
void print2Power(int n)
{
	if (n==0) {
			cout<<1;
			return;
			}
	int temp=2;
	temp=pow(temp,n/2);
	print2Power(n-1);
	if (n%2==0) {
				cout<<" "<<temp*temp;
				}
	else {
				cout<<" "<<temp*temp*2;
		}
	
}
int main()
{
	print2Power(5);
	//int A[]={1, 5, -1, 20, 6};
	//int n = sizeof(A)/sizeof(int);
	//cout << getMax(A, n) <<endl;
}


#include<iostream>
using namespace std;
int modulok(int x, int n, int m)
{
	if (n==0) return 1;
	else 
	{
		int temp=modulok(x,n/2,m);
		if (n%2==0) return (temp*temp)%m;
		else return (((temp*temp)%m)*x)%m;
		}
}
int main()
{
	int x,n,m;
	cin>>x>>n>>m;
	cout<<modulok(x,n,m)<<endl;
}

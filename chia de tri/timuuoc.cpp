#include<iostream>
#include <stdlib.h>
using namespace std;
int GCD(int a, int b)
{
	if(a==0||b==0)
	{
		if (abs(a)!=0) return abs(a);
		return abs(b);
	}
	else if (a%b==0||b%a==0)
	{
		return abs(a)>abs(b)?abs(b):abs(a);
	}
	else
	{
		return abs(a)>abs(b)?GCD(abs(a)-abs(b),abs(b)):GCD(abs(b)-abs(a),abs(a));
	}
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<GCD(a,b)<<endl;
}

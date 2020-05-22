#include<iostream>
using namespace std;
void findBoundingBox(const char* test)
{
	int size,xmax,ymax,xmin,ymin,x,y;
	freopen(test,"r",stdin);
	cin>>size;
	if (size>0)
	{
		cin>>xmin;
		cin>>ymin;
		xmax=xmin;
		ymax=ymin;
	}
	for (int i=1;i<size;i++)
	{
		cin>>x;
		cin>>y;
		if (x>xmax) xmax=x;
		if (x<xmin) xmin=x;
		if (y>ymax) ymax=y;
		if (y<ymin) ymin=y;
	}
	long long max=(xmax-xmin)>(ymax-ymin)?((long long)xmax-xmin):((long long)ymax-ymin);
	cout<<max*max;
}
int main()
{
	findBoundingBox("testbounding.txt");
}

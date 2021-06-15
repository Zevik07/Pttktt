#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
void swap(double *a,double *b)
{
	double temp=*a;
	*a=*b;
	*b=temp;
}
void Antrom()
{
	int n;
	double kq=0,Weight;
	//freopen("knapsack04.inp","r",stdin);
	cin>>n;
	cin>>Weight;
	double price[n],w[n],k[n];
	for (int i=0;i<n;i++)
	{
		cin>>price[i];
	}
	for (int i=0;i<n;i++)
	{
		cin>>w[i];
	}
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (price[j]/w[j]>price[i]/w[i])
			{
				swap(&price[j],&price[i]);
				swap(&w[j],&w[i]);
			}
		}
	}
	//w[i] la gia tri
	int i=0;
	while (Weight>0&&i<n)
	{
            if (w[i] <= Weight)
            { 
                Weight -= w[i];
                kq += price[i];
                //printf("them price1: %f\n",price[i]);
            }
            if (price[i]>Weight)
            {
            	kq+=(price[i]/w[i])*Weight;
            	//printf("them price2: %f\n",(price[i]/w[i])*price[i]);
            	Weight=0;
			}
			++i;
    }
   	printf("%.4f",kq);
}
int main()
{
	Antrom();
}

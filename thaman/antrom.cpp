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
void max_heap(double Q[],double K[],int i, int heap_size) {
    int largest; 
    int left = 2*i+1;
    int right = 2*i+2; 
    if (left < heap_size && Q[left]/K[left] > Q[i]/K[i])
        largest = left;
    else
        largest = i;
    if (right < heap_size && Q[right]/K[right] > Q[largest]/K[largest])
        largest = right;
    if (largest != i) {
        swap(&Q[i],&Q[largest]);
        swap(&K[i],&K[largest]);
        max_heap(Q,K,largest, heap_size); 
    }
}
void heap_sort(double Q[],double K[],int size)
{
	for (int i = size / 2; i >= 0; i--)
        max_heap(Q,K,i,size); 
    for(int i = size-1; i>=0 ; i-- )
    {
        swap(&Q[0],&Q[i]);
        swap(&K[0],&K[i]);
        max_heap(Q,K, 0, i);
    }
}
void Antrom()
{
	int n;
	double Weight,kq;
	freopen("knapsack04.inp","r",stdin);
	cin>>n;
	cin>>Weight;
	double w[n],p[n];
	for (int i=0;i<n;i++)
	{
		cin>>w[i];
	}
	for (int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	heap_sort(p,w,n);
	for (int i = n-1; i >= 0; i--) 
        { 
            if (w[i] <= Weight) 
            { 
                Weight -= w[i]; 
                kq += p[i];
            }
            if (w[i]>Weight&&Weight>0)
            {
            	kq+=(Weight/w[i])*p[i];
            	break;
			}
        }
   	printf("%.4f",kq);
}
int main()
{
	Antrom();
}

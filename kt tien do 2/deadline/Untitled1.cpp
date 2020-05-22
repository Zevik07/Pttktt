#include<stdio.h>
#include<stdlib.h>
int max(int a[],int size)
{
	int max=a[0];
	for(int i=1;i<size;i++)
	{
		if (a[i]>max) max=a[i];
	}
	return max;
}
void nhap(int a[],int size)
{
	for (int i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void max_heap(int *Q,int *D,int i, int heap_size) {
    int largest; 
    int left = 2*i+1;
    int right = 2*i+2; 
    if (left < heap_size && Q[left] > Q[i]) 
        largest = left;
    else
        largest = i;
    if (right < heap_size && Q[right] > Q[largest])
        largest = right;
    if (largest != i) {
        swap(&*(Q+i),&*(Q+largest));
        swap(&*(D+i),&*(D+largest));
        max_heap(Q, D,largest, heap_size);
    }
}
void heap_sort(int *Q,int *D, int size)
{
	for (int i = size / 2; i >= 0; i--) 
        max_heap(Q,D,i,size);
    for(int i = size-1; i>=0 ; i-- )
    {
        swap(&*(Q+0),&*(Q+i));
        swap(&*(D+0),&*(D+i));
        max_heap(Q,D,0,i);
    }
}
void deadline()
{
	int size;
	scanf("%d",&size);
	int p[size],d[size];
	nhap(p,size);nhap(d,size);
	int m=max(d,size);
	int *moc=(int*)calloc((m+1),sizeof(int));
	long long *kq=(long long *)calloc(1,sizeof(long long));
	heap_sort(p,d,size);
	for (int i=size-1;i>=0;i--)
	{
		int j=d[i];
		while (moc[j]>0) --j;
		if (j!=0){
				*kq+=(long long)p[i];
				moc[j]=p[i];
		}
	}
	printf("%lld",*kq);
	free(moc);
}
int main()
{
	deadline();
}

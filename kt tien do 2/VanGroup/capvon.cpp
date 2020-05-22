#include <stdio.h>
#include <stdlib.h>
void nhap(int *arr,int size)
{
	for (int i=0;i<size;i++)
	{
		scanf("%d",(arr+i));
	}
}
void XuatMang(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, *(arr + i));
    }
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void max_heap(int *Q,int i, int heap_size) {
    int largest; 
    int left = 2 * i+1;
    int right = 2 * i + 2; 
    if (left < heap_size && Q[left] > Q[i]) 
        largest = left;
    else
        largest = i;
    if (right < heap_size && Q[right] > Q[largest])
        largest = right;
    if (largest != i) {
        swap(&*(Q+i),&*(Q+largest));
        max_heap(Q, largest, heap_size); 
    }
}
void heap_sort(int *Q, int size)
{
	for (int i = size / 2; i >= 0; i--) 
        max_heap(Q, i,size);
    for(int i = size-1; i>=0 ; i-- )
    {
        swap(&*(Q+0),&*(Q+i));
        max_heap(Q, 0, i);
    }
}
void estimateProfit(const char* temp)
{
	freopen(temp,"r",stdin);
	int size;
	scanf("%d",&size);
	int *p,*v;
	p = (int*)malloc(size*sizeof(int));
	v = (int*)malloc(size*sizeof(int));
	long long *tong=(long long *)calloc(1,sizeof(long long));
	nhap(p,size);nhap(v,size);
	heap_sort(p,size);heap_sort(v,size);
	for(int i=0;i<size;i++)
	{
		*tong+=((long long)*(p+i))*(*(v+i));
	}
	printf("%lld",*tong);
	free(tong);
	free(p);
	free(v);
}
int main()
{
	estimateProfit("vg10.inp");
}

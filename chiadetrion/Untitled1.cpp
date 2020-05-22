#include <stdio.h>
#include <stdlib.h>
#define MaxSize 1000000
typedef int KeyType;
typedef struct{
   KeyType *Keys;
   int size;
}PriorityQueue;
void swap(KeyType *a,KeyType *b)
{
	KeyType temp=*a;
	*a=*b;
	*b=temp;
}
void max_heap(PriorityQueue *Q,int i, int heap_size) {
    int largest; 
    int left = 2 * i+1;
    int right = 2 * i + 2; 
    if (left < heap_size && Q->Keys[left] > Q->Keys[i]) 
        largest = left;
    else
        largest = i;
    if (right < heap_size && Q->Keys[right] > Q->Keys[largest])
        largest = right;
    if (largest != i)
	{
        swap(&Q->Keys[i], &Q->Keys[largest]);
        max_heap(Q, largest, heap_size); 
    }
}
void heap_sort(PriorityQueue *Q)
{
	for (int i = Q->size / 2 - 1; i >= 0; i--) 
        max_heap(Q, i, Q->size); 
    for(int i = Q->size-1; i>=0 ; i-- )
    {
        swap(&Q->Keys[0],&Q->Keys[i]);
        max_heap(Q, 0, i);
    }
}
void decreaseKey(PriorityQueue *Q,int i,KeyType k)
{
	if (k>Q->Keys[i]) return;
    Q->Keys[i]=k;
    while (i>0 && Q->Keys[(i-1)/2] > Q->Keys[i])
    {
        swap(&Q->Keys[(i-1)/2],&Q->Keys[i]);
        i=(i-1)/2;
    }
}
void insert(PriorityQueue *Q, KeyType val)
{
	Q->size++;
	Q->Keys[Q->size-1]=val;
	decreaseKey(Q,Q->size-1,val);
}
int search1(PriorityQueue Q,KeyType val, int start, int end)
{
	while (start<=end)
	{
		int mid=(start+end)/2;
		if(Q.Keys[mid]<val) start=mid+1;
		else if(Q.Keys[mid]>val) end=mid-1;
		else return mid;
	}
	return -1;
}
void search(const char* file)
{
	int n,q;
	KeyType Temp;
	PriorityQueue Q;
	Q.size=0;
	Q.Keys=(KeyType*)malloc(MaxSize*sizeof(KeyType));
	freopen(file,"r",stdin);
	scanf("%d",&n);
	scanf("%d",&q);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&Temp);
		insert(&Q,Temp);
	}
	heap_sort(&Q);
	for (int i=0;i<q;i++)
	{
		scanf("%d",&Temp);
		if (search1(Q,Temp,0,Q.size-1)!=-1) printf("YES\n");
		else printf("NO\n");
	}
	
}
int main()
{
	search("test.txt");
}

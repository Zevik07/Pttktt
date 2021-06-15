#include<stdio.h>
#define MaxSize 100000
#define MINVALUE -32768
typedef int KeyType;
typedef struct{
   KeyType Keys[MaxSize];
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
    if (largest != i) {
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
int search(PriorityQueue Q,int key,int start, int end)
{
	int i=(start+end)/2;
	while (start!=i and i!=end)
	{
		if (Q.Keys[i]>=key) end=i;
		else start=i;
		i=(start+end)/2;
	}
	for (i=start;i<=end;i++)
	{
		if (Q.Keys[i]>=key) break;
	}
	return i;
}
void shootOut(const char *b5)
{
	PriorityQueue pQ;
	pQ.size=0;
	int size,q;
	//nhap va sapxep suc manh
	freopen(b5,"r",stdin);
	scanf("%d",&size);
	for (int i=1;i<=size;i++)
	{
		scanf("%d",&pQ.Keys[i]);
		pQ.size++;
	}
	heap_sort(&pQ);
	//Tao mang tong suc manh thu i
	int tong[size];
	tong[1]=pQ.Keys[1];
	for (int i=2;i<=size;i++)
	{
		tong[i]=tong[i-1]+pQ.Keys[i];
	}
	//Tinh so muc tieu bi nga va tong suc manh theo tung vong
	scanf("%d",&q);
	int m=0;
	for (int i=0;i<q;i++)
	{
		scanf("%d",&m);
		int temp=search(pQ,m,1,pQ.size);
		printf("%d %d\n",temp-1,tong[temp-1]);
	}
	printf("\n----------------\n");
	for (int i=1;i<=size;i++)
	{
		printf("%d ",tong[i]);
	}
}
int main()
{
	shootOut("test.txt");
}

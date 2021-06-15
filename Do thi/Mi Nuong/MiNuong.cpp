#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100000
struct Node
{
	int start;
	int end;
};
struct Node* List[MaxSize];
struct Node* L;
void nhap(List *L,int n)
{
	for (int i=1;i<=n;i++)
	{
		(*L)[i]=(struct Node*)malloc(sizeof(struct Node));
		scanf("%d",&((*L)[i]->start));
		scanf("%d",&((*L)[i]->end));
	}
}
void nhapk(int d[],int k)
{
	for(int i=0;i<k;i++)
	{
		scanf("%d",&d[i]);
	}
}
void xuat(List L, int n)
{
	for (int i=1;i<=n;i++)
	{
		printf("\n%d %d",L[i]->start,L[i]->end);
	}
}
//Hang uu tien
struct KeyType
{
	int start;
	int end;
};
typedef struct
{
	KeyType *Keys;
	int size;
} PriorityQueue;
void swap(KeyType *a,KeyType *b)
{
	KeyType temp=*a;
	*a=*b;
	*b=temp;
}
void makenull(PriorityQueue *Q)
{
	Q->size=0;
}
int isEmpty(PriorityQueue Q)
{
	return Q.size==0;
}
void minHeapify(PriorityQueue *Q,int i, int heap_size) {
    int smallest; 
    int left = 2 * i+1;
    int right = 2 * i + 2; 
    if (left < heap_size && Q->Keys[left].Key < Q->Keys[i].Key) 
        smallest = left;
    else
        smallest = i;
    if (right < heap_size && Q->Keys[right].Key < Q->Keys[smallest].Key)
        smallest = right;
    if (smallest != i) {
        swap(&Q->Keys[i], &Q->Keys[smallest]);
        minHeapify(Q, smallest, heap_size); 
    }
}
KeyType extractMin(PriorityQueue *Q)
{
	KeyType k=Q->Keys[0];
	swap(&Q->Keys[0],&Q->Keys[Q->size-1]);
	--Q->size;
	minHeapify(Q,0,Q->size);
	return k;
}
void decreaseKey(PriorityQueue *Q,int i,KeyType k)
{
	if (k.Key>Q->Keys[i].Key) return;
    Q->Keys[i]=k;
    while (i>0 && Q->Keys[(i-1)/2].Key > Q->Keys[i].Key)
    {
        swap(&Q->Keys[(i-1)/2],&Q->Keys[i]);
        i=(i-1)/2;
    }
}
void insert(PriorityQueue *Q, KeyType val)
{
	Q->size++;
	Q->Keys[Q->size-1].Key=val.Key;
	Q->Keys[Q->size-1].Vertex=val.Vertex;
	decreaseKey(Q,Q->size-1,val);
}
//Tim kiem nhi phan
int main()
{
	int n,k;
	int d[k];
	scanf("%d",&n);
	nhap(&L,n);
	scanf("%d",&k);
	nhapk(d,k);
}

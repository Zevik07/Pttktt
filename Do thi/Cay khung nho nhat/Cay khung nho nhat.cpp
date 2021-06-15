#include <stdio.h>
#include <stdlib.h>
int M,N;
//Khoi tao djs
void Khoitao(int *parent, int *rank, int N)
{
	for(int i=0;i<=N;i++)
	{
		*(parent+i)=i;
		*(rank+i)=0;
	}
}
int find(int x, int *parent)
{
	if (*(parent+x)!=x)
	*(parent+x)=find(*(parent+x),parent);
	return *(parent+x);
}
void Union(int x,int y,int *parent,int *rank)
{
	int r1 = find(x,parent);
 	int r2 = find(y,parent);
	if (*(rank+r1) < *(rank+r2))
 			*(parent+r1) = r2;
 	else if (*(rank+r1) > *(rank+r2))
 			*(parent+r2) = r1;
	else{
		*(parent+r2) = r1;
		(*(rank+r1))++;
	}
}
//hang uu tien
typedef struct{
	int start;
	int end;
	int weight;
} KeyType;
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
void makenull(PriorityQueue *Q)
{
	Q->size=0;
}
void maxHeapify(PriorityQueue *Q,int i, int heap_size) {
    int smallest; 
    int left = 2 * i+1;
    int right = 2 * i + 2; 
    if (left < heap_size && Q->Keys[left].weight > Q->Keys[i].weight) 
        smallest = left;
    else
        smallest = i;
    if (right < heap_size && Q->Keys[right].weight > Q->Keys[smallest].weight)
        smallest = right;
    if (smallest != i) {
        swap(&Q->Keys[i], &Q->Keys[smallest]);
        maxHeapify(Q, smallest, heap_size); 
    }
}
void decreaseKey(PriorityQueue *Q,int i,KeyType k)
{
    if (k.weight>=Q->Keys[i].weight)
    {
        Q->Keys[i]=k;
        while (i>0 && Q->Keys[(i-1)/2].weight < Q->Keys[i].weight)
        {
            swap(&Q->Keys[(i-1)/2],&Q->Keys[i]);
            i=(i-1)/2;
        }
    }
}
void insert(PriorityQueue *Q, KeyType val)
{
	Q->size++;
	Q->Keys[Q->size-1].weight=val.weight;
	Q->Keys[Q->size-1].start=val.start;
	Q->Keys[Q->size-1].end=val.end;
	decreaseKey(Q,Q->size-1,val);
}
void heapsort(PriorityQueue *Q, int size)
{
	for (int i = size / 2; i >= 0; i--) 
        maxHeapify(Q, i, size);
    for(int i = size-1; i>=0 ; i-- )
    {
        swap(&Q->Keys[0],&Q->Keys[i]);
        maxHeapify(Q, 0, i);
    }
}
void findCost(const char* test)
{
	PriorityQueue Q;
	makenull(&Q);
	freopen(test,"r",stdin);
	//Nhap cac thong so
	scanf("%d %d",&N,&M);
	int parent[N];
	int rank[N];
	Khoitao(parent,rank,N);
	Q.Keys=(KeyType*)malloc(M*sizeof(KeyType));
	for(int i=0;i<M;i++)
	{
		KeyType temp;
		scanf("%d ",&temp.start);
		scanf("%d ",&temp.end);
		scanf("%d ",&temp.weight);
		insert(&Q,temp);
	}
	heapsort(&Q,M);
//	for(int i=0;i<M;i++)
//	{
//		printf("\n%d %d %d",Q.Keys[i].start,Q.Keys[i].end,Q.Keys[i].weight);
//	}
	int j=0;
	int i=0;
	int tong=0;
	while (j!=N-1 and i!=M-1)
	{
		KeyType e=Q.Keys[i];
		int x=find(e.start,parent);
		int y=find(e.end,parent);
		if (x!=y)
		{
			tong += e.weight;
			Union(x,y,parent,rank);
			j++;
		}
		i++;
	}
	printf("%d",tong);
	free(Q.Keys);
}
int main()
{
	findCost("Test.txt");
}

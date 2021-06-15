#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10000
#define VLMAX 1000000000
struct Node{
	int vertex;
	int weight; 
	struct Node* Next;
};
typedef struct Node* List[MaxSize+1];
List L;
int M,N;
void init (List *p,int N)
{
	for(int i=0;i<=N;i++)
	{
		(*p)[i]=(struct Node*)malloc(sizeof(struct Node));
		(*p)[i]->Next=NULL;
	}
}
void insertNode(List *p,int u, int v, int w)
{
	struct Node* Temp=(struct Node*)malloc(sizeof(struct Node));
	Temp->vertex=v;
	Temp->weight=w;
	Temp->Next=(*p)[u]->Next;
	(*p)[u]->Next=Temp;
}
//void xoalist(struct Node* L)
//{
//		struct Node *q;
//		struct Node *p=L;
//		while(p->Next!=NULL)
//		{
//			q=p->Next;
//			p->Next=q->Next;
//			free(q);
//		}
//}

//Hang uu tien
typedef struct{
	int Vertex;
	int Key;
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
void calculateDistance(const char* test)
{
	freopen(test,"r",stdin);
	//Nhap cac thong so
	scanf("%d %d",&N,&M);
	init(&L,N);
	int u,v,w;
	for (int i=0;i<M;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		insertNode(&L,u,v,w);
	}
	//xong phan nhap
	int d[N+1], danhdau[N+1],a;
	PriorityQueue Q;
	for (int i=0;i<=N;i++)
	{
		d[i]=VLMAX;
		danhdau[i]=0;
	}
	d[1]=0;
	KeyType Temp,Temp2;
	Node *Temp3;
	Temp.Key=0;
	Temp.Vertex=1;
	makenull(&Q);
	Q.Keys=(KeyType*)malloc((VLMAX)*sizeof(KeyType));
	insert(&Q,Temp);
	while (!isEmpty(Q))
	{
		Temp=extractMin(&Q);
		//printf("\n%d ",Temp.Vertex);
		a=Temp.Vertex;
		if (danhdau[a]==1) continue;
		danhdau[a]=1;
		Temp3=(L)[a];
		while(Temp3->Next!=NULL)
		{
			int weight=Temp3->Next->weight;
			int v=Temp3->Next->vertex;
			if (d[a]+weight<d[v])
			{
				d[v]=d[a]+weight;
				Temp2.Key=d[v];
				Temp2.Vertex=v;
				insert(&Q,Temp2);
			}
			Temp3=Temp3->Next;
		}
	}
	for (int i=2;i<=N;i++)
	{
		printf("%d ",d[i]);
	}
	free(Q.Keys);
//	for (int i=0;i<=N;i++)
//	{
//		xoalist(L[i]);
//	}
}
int main()
{
	calculateDistance("input01.inp");
}

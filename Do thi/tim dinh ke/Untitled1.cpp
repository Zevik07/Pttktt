#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MaxSize 10000
struct Node{
	int vertex; 
	int weight; 
	struct Node* Next;
};
typedef struct Node* List[MaxSize];
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
void dinhke(List p,int u)
{
	Node *Temp=(p)[u];
	while (Temp->Next!=NULL)
	{
		printf("%d ",Temp->Next->vertex);
		Temp=Temp->Next;
	}
}
int ktke(List p, int u ,int v)
{
	Node *Temp=(p)[u];
	while (Temp->Next!=NULL)
	{
		if (Temp->Next->vertex==v) return 1;
		Temp=Temp->Next;
	}
	return 0;
}
void xuat(List p,int N)
{
	for(int i=1;i<=N;i++)
	{
		Node *Temp=(p)[i];
		printf("\n");
		while (Temp->Next!=NULL)
		{
			
			printf("%d ",Temp->Next->vertex);
			Temp=Temp->Next;

		}
	}
}
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
    int largest; 
    int left = 2 * i+1;
    int right = 2 * i + 2; 
    if (left < heap_size && Q->Keys[left].Key < Q->Keys[i].Key) 
        largest = left;
    else
        largest = i;
    if (right < heap_size && Q->Keys[right].Key < Q->Keys[largest].Key)
        largest = right;
    if (largest != i) {
        swap(&Q->Keys[i], &Q->Keys[largest]);
        minHeapify(Q, largest, heap_size); 
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
    if (k.Key<=Q->Keys[i].Key)
    {
        Q->Keys[i]=k;
        while (i>0 && Q->Keys[(i-1)/2].Key > Q->Keys[i].Key)
        {
            swap(&Q->Keys[(i-1)/2],&Q->Keys[i]);
            i=(i-1)/2;
        }
    }
}
void insert(PriorityQueue *Q, KeyType val)
{
	Q->size++;
	Q->Keys[Q->size-1].Key=INT_MAX;
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
	int d[N+1],danhdau[N+1],a,b;
	PriorityQueue Q;
	makenull(&Q);
	for (int i=0;i<=N;i++)
	{
		d[i]=INT_MAX;
		danhdau[i]=0;
	}
	d[1]=0;
	KeyType Temp,Temp2;
	Node *Temp3;
	Temp.Key=0;
	Temp.Vertex=1;
	Q.Keys=(KeyType*)malloc(N*sizeof(KeyType));
	insert(&Q,Temp);
	while (!isEmpty(Q))
	{
		Temp=extractMin(&Q);
		a=Temp.Vertex;
		b=Temp.Key;
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
		if(d[i]!=INT_MAX) printf("%d ",d[i]);
		else printf("%d ",1000000000);
	}
	free(Q.Keys);
}
int main()
{
	calculateDistance("test.txt");
}

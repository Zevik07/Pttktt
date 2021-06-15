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
void min_heap(PriorityQueue *Q,int i, int heap_size) {
    int largest; 
    int left = 2 * i+1;
    int right = 2 * i + 2; 
    if (left < heap_size && Q->Keys[left] < Q->Keys[i]) 
        largest = left;
    else
        largest = i;
    if (right < heap_size && Q->Keys[right] < Q->Keys[largest])
        largest = right;
    if (largest != i) {
        swap(&Q->Keys[i], &Q->Keys[largest]);
        min_heap(Q, largest, heap_size);
    }
}
void heap_sort(PriorityQueue *Q)
{
	for (int i = Q->size / 2; i >= 0; i--) 
        min_heap(Q, i, Q->size); 
    for(int i = Q->size-1; i>=0 ; i-- )
    {
        swap(&Q->Keys[0],&Q->Keys[i]);
        min_heap(Q, 0, i);
    }
}
void decreaseKey(PriorityQueue *Q,int i,KeyType k)
{
    if (k>=Q->Keys[i])
    {
        while (i>0 && Q->Keys[(i-1)/2] < Q->Keys[i])
        {
            swap(&Q->Keys[(i-1)/2],&Q->Keys[i]);
            i=(i-1)/2;
        }
    }
}
void insert(PriorityQueue *Q, KeyType val)
{
	Q->size++;
	Q->Keys[Q->size-1]=val;
	decreaseKey(Q,Q->size-1,val);
}
void findkSum (const char* b4){
	PriorityQueue pQ;
	pQ.size=0;
	KeyType temp;
	freopen(b4,"r",stdin);
    int n=0,q=0,k=0;
    scanf("%d",&n);
    scanf("%d",&q);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        insert(&pQ,temp);
	}
	heap_sort(&pQ);
	//Dung mang chu tong cua i diem so
	int kq[n];
	kq[0]=pQ.Keys[0];
    for (int i=1;i<n;i++)
    				kq[i]=kq[i-1]+pQ.Keys[i];
	for (int i=0;i<q;i++)
	{
		scanf("%d",&k);
		printf("%d ",kq[k-1]);
	}
}
int main()
{
	findkSum("test.txt");
}

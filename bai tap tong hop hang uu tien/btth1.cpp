#include <stdio.h>
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
long long tichba(PriorityQueue Q)
{
	if (Q.size<=2) {
					return -1;
						}
	else {
					return ((long long)Q.Keys[Q.size-1])*Q.Keys[Q.size-2]*Q.Keys[Q.size-3];
					}
}
void insert(PriorityQueue *Q, int val)
{
    Q->size = Q->size + 1;
    int i = Q->size-1;
    Q->Keys[i] = val;
    while( i > 0 && Q->Keys[ (i-1)/2] < Q->Keys[ i ])
    {
        swap(&Q->Keys[ (i-1)/2 ], &Q->Keys[ i ]);
        i = (i-1)/2;
    }
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
	for (int i = Q->size / 2; i >= 0; i--) 
        max_heap(Q, i, Q->size); 
    for(int i = Q->size-1; i>=0 ; i-- )
    {
        swap(&Q->Keys[0],&Q->Keys[i]);
        max_heap(Q, 0, i);
    }
}
int main()
{
	PriorityQueue Q;
    Q.size=0;
    int N;
	scanf("%d",&N);
	int A[N];
	for (int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
	}
	for (int i=0;i<N;i++)
	{
		insert(&Q,A[i]);
		heap_sort(&Q);
		printf("%lld\n",tichba(Q));
	}
}

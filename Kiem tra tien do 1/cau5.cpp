#include<stdio.h>
#define MaxSize 100000
#define MINVALUE -32768
typedef int KeyType;
typedef struct{
   KeyType Keys[MaxSize];
   int size;
   int stt[MaxSize];
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
void shootOut(const char *b5)
{
	PriorityQueue pQ,temp;
	int size,round;
	freopen(b5,"r",stdin);
	scanf("%d",&size);
	pQ.size=size;
	for (int i=0;i<size;i++)
	{
		scanf("%d",&pQ.Keys[i]);
		pQ.stt[i]=i;
	}
	scanf("%d",&round);
	temp.size=round;
	temp2=pQ.size;
	for (int i=0;i<round;i++)
	{
		scanf("%d",&temp.Keys[i]);
		temp.stt=temp2++;
	}
	for (int i=0;i<round;i++)
	for (int i=0;i<pQ.size;i++)
	{
		if(pQ.Keys[i]!=temp.Keys[i]||pQ.Keys[i]==temp.Keys[i])
	}
	

}
int main()
{
	shootOut("test.txt");
}

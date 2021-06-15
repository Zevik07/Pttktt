// kiem tra tien do 1
#include <stdio.h>
#define MaxSize 100000
#define MINVALUE -32768
typedef int KeyType;
typedef struct{
   KeyType Keys[MaxSize];
   int size;
   int stt[MaxSize];
}PriorityQueue;
int k=0; //so chia
void swap(KeyType *a,KeyType *b)
{
	KeyType temp=*a;
	*a=*b;
	*b=temp;
}
void max_heap(PriorityQueue *temp,int i, int heap_size) {
	int largest=i;
    int left = 2 * i+1;
    int right = 2 * i + 2;
    if (left < heap_size) 
		{
			if (temp->Keys[left]%k> temp->Keys[i]%k)
        					largest = left;
        	if (temp->Keys[left]%k==temp->Keys[i]%k && temp->stt[left]>temp->stt[i])
        					largest = left;
        }
    if (right < heap_size) 
		{
	 		if (temp->Keys[right]%k> temp->Keys[largest]%k)
	 						largest=right;
	 		if (temp->Keys[right]%k==temp->Keys[largest]%k && temp->stt[right]>temp->stt[largest])
	 						largest=right;
	 	}
    if (largest != i) {
        swap(&temp->Keys[i],&temp->Keys[largest]);
        swap(&temp->stt[i],&temp->stt[largest]);
        max_heap(temp, largest, heap_size);
    					}
}
void heap_sort(PriorityQueue *temp)
{
	for (int i = temp->size / 2; i >= 0; i--) 
        max_heap(temp, i, temp->size);
    for(int i = temp->size-1; i>=0 ; i-- )
    {
        swap(&temp->Keys[0],&temp->Keys[i]);
        swap(&temp->stt[0],&temp->stt[i]);
        max_heap(temp, 0, i);
    }
}
void moduloSort(const char* b3)
{
	PriorityQueue pQ;
	int size;
	freopen(b3,"r",stdin);
	scanf("%d",&size);
	scanf("%d",&k);
	pQ.size=size;
	for (int i=0;i<size;i++)
		{
			scanf("%d",&pQ.Keys[i]);
			pQ.stt[i]=i+1;
		}
	heap_sort(&pQ);
	for (int i=0;i<size;i++)
		{
				printf("%d ",pQ.Keys[i]);
		}
}
void merge (PriorityQueue *Q,int l, int m, int r)
{
	int size1=m-l+1;
	int size2=r-m;
	PriorityQueue temp1,temp2;
	temp1.size=size1;
	temp2.size=size2;
	for(int i=0;i<size1;i++)
	{
		temp1.Keys[i]=Q->Keys[l+i];
	}
	for (int i=0;i<size2;i++)
	{
		temp2.Keys[i]=Q->Keys[m+1+i];
	}
	int i=0;
	int j=0;
	int k=l;
	while (i<size1 && j<size2)
	{
		if (temp1.Keys[i]<=temp2.Keys[i])
		{
			Q->Keys[k]=temp1.Keys[i];
			i++;
		}
		else 
		{
			Q->Keys[k]=temp2.Keys[i];
			i++;
		}
		k++;
	}
	while (i<size1)
	{
		Q->Keys[k]=temp1.Keys[i];
		i++;
		k++;
	}
	while (j<size2)
	{
		Q->Keys[k]=temp2.Keys[i];
		j++;
		k++;
	}
}
void mergeSort(PriorityQueue *Q,int l,int r)
{
	if (l<r)
	{
		int mid=(l+r)/2;
		mergeSort(Q,l,mid);
		mergeSort(Q,mid+1,r);
		merge(Q,l,mid,r);
	}
}
int main()
{

}

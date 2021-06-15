#include<stdio.h>
int main()
{
	int size;
	scanf("%d",&size);
	int a[size];
	for(int i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	int tong=a[0];
	//thuat toan brute force tim day con co tong lon nhat
	for(int i = 0; i < size; i++) 
	{
    	int sum = 0;
    	for (int j = i; j < size; j++) {
        	sum += a[j];
        	if (sum > tong) tong = sum;
    	}
	}
    //Thuat toan Kadane do phuc tap O(n) 
    int max_so_far=a[0];
	int max_ending_here=max_so_far;
    for (int i=1;i<size;i++)
    	{
    	max_ending_here=a[i]>(a[i]+max_ending_here)?a[i]:(a[i]+max_ending_here);
    	max_so_far=max_so_far>max_ending_here?max_so_far:max_ending_here;
	}
	
	printf("(Brute-force)Day con lon nhat la: %d",tong);
	printf("\n(Kadane): %d",max_so_far);
}

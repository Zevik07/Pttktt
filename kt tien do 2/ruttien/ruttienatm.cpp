#include <stdio.h>
void withDraw(int A[], int n){
	int i=0;
	int X[6]={0,0,0,0,0,0};
	while (n!=0)
		{
			X[i]=n/A[i];
			n=n%A[i];
			++i;;
		}
	for(int j=0;j<6;j++)
	{
		if (X[j]!=0) printf("%d VND: %d\n",A[j],X[j]);
	}
}
int main(){
	int tien[6]={500000, 200000, 100000, 50000, 20000, 10000};
	int n;
	scanf("%d",&n);
	if(n%10000 != 0) 
	{
		printf("KHONG RUT DUOC");
	}
	else withDraw(tien,n);
	
}

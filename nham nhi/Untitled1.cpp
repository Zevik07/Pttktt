#include <stdio.h>
int giaithua(int n)
{
	if (n==1) return 1;
	else return giaithua(n-1)*n;
}
int main()
{
	printf("%d",giaithua(2));
}

#include<stdio.h>
#include<math.h>
int ngtonn(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
        if (n%i == 0)
            return 0;
    return 1;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=n;i>1;i--)
	{
		if (ngtonn(i)) 
		{
			printf("%d",i);
			break;
		}
	}
}

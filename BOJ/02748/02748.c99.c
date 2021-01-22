#include <stdio.h>

int main()
{
	int num,i;
	long long int f[91];
	f[0] = 0,	f[1] = 1;
	scanf("%d",&num);
	if(num==0)
	{
		printf("%d",f[0]);
	}
	else if(num==1)
	{
		printf("%d",f[1]);
	}
	else if(num<=90)
	{		
	for(i=2; i<=num; i++)
	{
		f[i]=f[i-2]+f[i-1];
	}
	printf("%lld",f[num]);
}
	
}
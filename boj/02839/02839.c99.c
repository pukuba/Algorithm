#include <stdio.h>

int main()
{
	int a=0,b=0;
	scanf("%d",&a);
	while(1)
	{
		if(a%5==0)
		{
			printf("%d",a/5+b);
			break;
		}
		a-=3;
		b++;
		if(a<0)
		{
			printf("-1");
			break;
		}
	}
}
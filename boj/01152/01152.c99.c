#include <stdio.h>
#define MAX 1000001

int main()
{
	char str[MAX];
	int num=1;
	int i=0;
	
	gets(str);
	while(str[i]!='\0')
	{
		if(str[i]==' ' && str[i+1] !='\0')
		{
			num++;
		}
		i++;
	}
	if(str[0] == '\0' || str[0]==' ')
	{
		num--;
	}
	printf("%d\n",num);
	
}
#include <stdio.h>

int main(){
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	if(a>b) printf(">");
	if(a<b) printf("<");
	if(a==b) printf("==");
}
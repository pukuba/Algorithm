#include <stdio.h>

int main(){
	int a,ans=0;
	scanf("%d",&a);
	for(int i=5; i<=a; i*=5){
		ans+=a/i;
	}
	printf("%d",ans);
} 
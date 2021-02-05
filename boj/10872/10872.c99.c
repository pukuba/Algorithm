#include <stdio.h>

int main(){
	int n,ans=1;
	scanf("%d",&n);
	if(n==0){
		printf("1\n");
		return 0;
	}
	for(int i=1; i<=n; i++){
		ans*=i;
	}
	printf("%d\n",ans);
} 
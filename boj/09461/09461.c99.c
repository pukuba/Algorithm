#include <stdio.h>

int main(){
	long long d[101];
	d[1]=1,d[2]=1,d[3]=1,d[4]=2,d[5]=2,d[6]=3,d[7]=4,d[8]=5,d[9]=7,d[10]=9;
	for(int i=11; i<=100; i++){
		d[i]=d[i-1]+d[i-5];
	}
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		printf("%lld\n",d[n]);
	}	
}
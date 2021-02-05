#include <stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	for(int i=1; i<=N*2; i++){
		if(i%2!=0){
			for(int j=1; j<=(N+1)/2; j++){
				printf("* ");
			}
		}
		else{
			for(int j=1; j<=N/2; j++){
				printf(" *");
			}
		}
		printf("\n");
	}
} 
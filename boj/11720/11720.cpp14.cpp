#include <iostream>

using namespace std;
int main(){
	int t,sum=0;
	cin>>t;
	while(t--){
		int n=0;
		scanf("%1d",&n);
		sum+=n;
	} 
	printf("%d\n",sum);
}
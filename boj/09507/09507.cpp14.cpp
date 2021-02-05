#include <iostream>

using namespace std;
int main(){
	unsigned long long d[68]={1,1,2,4,0};
	for(int i=4; i<68; i++){
		d[i]=d[i-4]+d[i-3]+d[i-2]+d[i-1];
	}
	int n;cin>>n;
	while(n--){
		int x;
		cin>>x;
		cout<<d[x]<<'\n';
	}
}
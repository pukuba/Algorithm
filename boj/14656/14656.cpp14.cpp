#include <iostream>

using namespace std;
int main(){
	int n,st,ans=0;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>st;
		if(st!=i){
			ans++;
		}
	}
	cout<<ans;
}
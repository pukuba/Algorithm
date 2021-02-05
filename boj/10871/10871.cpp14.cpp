#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T,x,a;
	cin>>T>>x;
	while(T--){
		cin>>a;
		if(a<x){
			cout<<a<<' ';
		}
	}
}
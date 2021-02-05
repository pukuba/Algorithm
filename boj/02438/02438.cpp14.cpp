#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int starsu;
	cin>>starsu;
	for(int i=1; i<=starsu; i++){
		for(int j=1; j<=i; j++){
			cout<<"*";
		}
		cout<<'\n';
	}
}
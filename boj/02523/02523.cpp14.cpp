#include <iostream>

using namespace std;
int main(){
	int a;
	cin>>a;
	for(int i=1; i<=a; i++){
		for(int j=1; j<=i; j++){
			cout<<"*";
		}
		cout<<'\n';
	}
	for(int i=1; i<=a-1; i++){
		for(int j=a; j>=i+1; j--){
			cout<<"*";
		}
		cout<<'\n';
	}
}
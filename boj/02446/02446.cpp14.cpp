#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int input;
	cin>>input;
	for(int i=1; i<=input; i++){
		for(int j=1; j<i; j++){
			cout<<' ';
		}
		for(int j=input*2+1; j>i+i; j--){
			cout<<"*";
		}
		cout<<'\n';
	}
	for(int i=1; i<input; i++){
		for(int j=input; j>i+1; j--){
			cout<<' ';
		}
		for(int j=0; j<=i+i; j++){
			cout<<"*";
		}
		cout<<'\n';
	}
}
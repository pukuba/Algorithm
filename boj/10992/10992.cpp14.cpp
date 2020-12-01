#include <iostream>

//마지막죽은 (input*2)-1 
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int input;
	cin>>input;
	for(int i=1; i<input; i++){
		cout<<' ';
	} 
	cout<<"*";
	cout<<'\n';
	
	if(input>1){
		for(int i=1; i<input-1; i++){
			for(int j=input; j>i+1; j--){
				cout<<' ';
			}
			cout<<"*";
			for(int j=1; j<i+i; j++){
				cout<<' ';
			}
			cout<<"*";
			cout<<'\n';
		}
		for(int i=1; i<=(input*2)-1; i++){
			cout<<"*";
		}
	}
} 
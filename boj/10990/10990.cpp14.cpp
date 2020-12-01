#include <iostream>

using namespace std;
int main(){
	int N;
	cin>>N;
	for(int i=1; i<=N; i++){
		for(int j=i; j<N; j++){
			cout<<" ";
		}
		cout<<"*";
		for(int j=1; j<i+i-2; j++){
			cout<<" ";
		}
		if(i!=1){
			cout<<"*";
		}
		cout<<endl;
	}
} 
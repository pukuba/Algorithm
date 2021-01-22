#include <iostream>

using namespace std;
int main(){
	int N;
	cin>>N;
	for(int i=1; i<=N; i++){
		if(i%2!=0){
			for(int j=1; j<=N; j++){
				cout<<"* ";
			}
		}
		if(i%2==0){
			for(int j=1; j<=N; j++){
				cout<<" *";
			}
		}
		cout<<'\n';
	}
}
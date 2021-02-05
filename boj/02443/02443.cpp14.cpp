#include <iostream>

using namespace std;
int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		for(int j=1; j<=i; j++){
			cout<<' ';
		}
		for(int	j=i+i-1; j<=(T*2)-3; j++){
			cout<<"*";
		}
		cout<<endl;
	}
	
}
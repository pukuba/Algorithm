#include <iostream>

using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int s;
		char ch;
		cin>>s>>ch;
		for(int i=1; i<=s; i++){
			cout<<ch;
		}
		cout<<'\n';
	}
}
#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int a,b,t,plus=0;
	cin>>t;
	while(t--){
		plus++;
		cin>>a>>b;
		cout<<"Case #"<<plus<<": "<<a+b<<endl;
	}
}
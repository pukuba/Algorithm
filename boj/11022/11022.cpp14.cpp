#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int t,a,b,cs=0;
	cin>>t;
	while(t--){
		cs++;
		cin>>a>>b;
		cout<<"Case #"<<cs<<": "<<a<<" + "<<b<<" = "<<a+b<<endl;
	}
}
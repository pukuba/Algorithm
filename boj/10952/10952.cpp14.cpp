#include <iostream>

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int a,b;
	while(cin>>a>>b){
		if(a==0&&b==0){
			return 0;
		}
		cout<<a+b<<endl;
	}
}
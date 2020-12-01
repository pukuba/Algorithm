#include <iostream>

using namespace std;
int main(){
	int a,ans=0;
	cin>>a;
	for(int i=5; i<=a; i*=5){
		ans+=a/i;
	}
	cout<<ans<<'\n';
} 
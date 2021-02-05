#include <iostream>

using namespace std;
int main(){
	long long int n,m;
	cin>>n>>m;
	m*=-1;
	if(n+m>0){
		cout<<n+m;
	}
	else if(n+m<0){
		cout<<(n+m)*-1;
	}
}
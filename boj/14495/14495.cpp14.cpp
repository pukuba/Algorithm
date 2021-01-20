#include <iostream>

using namespace std;
int main(){
	long long d[117];
	d[1]=d[2]=d[3]=1,d[4]=2;
	int n;
	cin>>n;
	for(int i=5; i<=n; i++){
		d[i]=d[i-1]+d[i-3];
	}
	cout<<d[n];
}
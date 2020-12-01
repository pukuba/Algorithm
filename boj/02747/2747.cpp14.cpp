#include <iostream>

using namespace std;
int main(){
	int d[46],n;
	d[0]=0,d[1]=1;
	cin>>n;
	for(int i=2; i<=n; i++){
		d[i]=d[i-2]+d[i-1]; 
	}
	cout<<d[n];
}
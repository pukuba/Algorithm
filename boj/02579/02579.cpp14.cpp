#include <iostream>
#include <algorithm>

using namespace std;
int d[301],ans,arr[301];
int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	d[1]=arr[1];
	d[2]=max(arr[1]+arr[2],arr[2]);
	d[3]=max(arr[1]+arr[3],arr[2]+arr[3]); 
	for(int i=4; i<=n; i++){
		d[i]=max(d[i-2]+arr[i],arr[i-1]+arr[i]+d[i-3]);
	}
	cout<<d[n];
}
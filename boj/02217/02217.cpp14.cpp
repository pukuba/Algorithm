#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int cmp(int a,int b){
	return a>b;
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n+1);
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end(),cmp);
	int ans=0; 
	for(int i=0; i<n; i++){
		ans=max(ans,v[i]*(i+1));
	}
	cout<<ans<<'\n';
}
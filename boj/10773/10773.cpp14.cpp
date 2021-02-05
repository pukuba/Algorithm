#include <iostream>
#include <vector>

using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		if(x!=0) v.push_back(x);
		else if(!v.empty()) v.pop_back();
	}
	int ans=0;
	for(int i=0; i<v.size(); i++){
		ans+=v[i];
	}
	cout<<ans<<'\n';
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i].second>>a[i].first;
	}
	sort(a.begin(),a.end());
	for(auto &s : a){
		cout<<s.second<<' '<<s.first<<'\n';
	}
}
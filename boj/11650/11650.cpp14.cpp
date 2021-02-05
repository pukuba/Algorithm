#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
	int T;
	cin>>T;
	vector<pair<int,int>> a(T);
	for(int i=0; i<T; i++){
		cin>>a[i].first>>a[i].second;
	}
	sort(a.begin(),a.end());
	for(int i=0; i<T; i++){
		cout<<a[i].first<<' '<<a[i].second<<'\n';
	}
}
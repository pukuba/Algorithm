#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
	int n;
	cin>>n;
	map<long long, int>d;
	while(n--){
		long long x;
		cin>>x;
		d[x]+=1;
	}
	int m=0;
	long long ans=0;
	for(auto &p : d){
		if(p.second > m){
			m = p.second;
			ans = p.first;
		} else if(p.second	== m && p.first <ans){
			ans = p.first;
		}
	}
	cout<<ans;
}
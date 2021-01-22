#include <bits/stdc++.h>

using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	vector<int> v; 
	for(int i=1; i<=b; i++){
		int x=a*i;
		string str=to_string(x);
		reverse(str.begin(),str.end());
		int ans=stoi(str);
		v.push_back(ans);
	}
	sort(v.begin(),v.end());
	cout<<v[b-1];
}
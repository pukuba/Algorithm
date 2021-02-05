#include <bits/stdc++.h>

using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int size=s.size();
		cout<<s[0]<<s[size-1]<<'\n';
	}
}
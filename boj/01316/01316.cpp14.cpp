#include <bits/stdc++.h>

using namespace std;
int main(){
	int n,ans=0;
	cin>>n;
	for(int i=0; i<n; i++){
		vector<int> a;
		string s;
		cin>>s;
		for(int i=0; i<s.size(); i++){
			if(i==0) a.push_back(s[i]);
			else{
				if(s[i]==s[i-1]) continue;
				else a.push_back(s[i]);
			}
		}
		sort(a.begin(),a.end());
		bool check=false;
		for(int i=0; i<a.size()-1; i++){
			if(a[i]==a[i+1]) check=true;
		}
		if(!check)ans++; 
	}
	cout<<ans<<'\n';
}
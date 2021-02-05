#include <bits/stdc++.h>

using namespace std;
string s;
int n;
int main(){
	cin>>n;
	while(n--){
		int b=0,a=0;
		cin>>s;
		for(int i=0; i<s.size(); i++){
			a = s[i]=='('?a+1:a-1;
			if(a<0) b=1;
		}
		if(a) b=1;
		if(b) cout<<"NO\n";
		else cout<<"YES\n";
	}
}
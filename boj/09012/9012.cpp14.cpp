#include <bits/stdc++.h>

using namespace std;
string s;
int a,b,n;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	while(n--){
		a=1; b=0;
		cin>>s;
		for(int i=0; i<s.size(); i++){
			if(s[i] == '(') b++;
			if(s[i] == ')') b--;
			if(b < 0) a = 0;
		}
		if(b!=0) a=0;
		cout<<(a ? "YES" : "NO")<<'\n';
	}
}
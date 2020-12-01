#include <bits/stdc++.h>

using namespace std;
string s;
int a,b,n;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(s.size()-1 != i&& s[i] == '(' && s[i+1] == ')') {
			i++;
			a += b;
		}
		else if(s[i] == '(') b++;
		else if(s[i] == ')') a++,b--;
	}
	cout<<a<<'\n';
}
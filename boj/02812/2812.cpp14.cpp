#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,m,k;
string s;
stack<char> stk;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>s;
	for(int i=0; i<s.size(); i++){
		if(!stk.size()) stk.push(s[i]);
		else if(stk.top() < s[i] && m > k){
			while(stk.size() && stk.top() < s[i] && m > k){
				stk.pop();
				k++;
			}
			stk.push(s[i]);
		}
		else stk.push(s[i]);
	}
	while(k < m) stk.pop(),k++;
	s = "";
	while(stk.size()){
		s += stk.top();
		stk.pop();
	}
	reverse(s.begin(),s.end());
	cout<<s;
}
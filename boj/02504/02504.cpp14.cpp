#include <bits/stdc++.h>

using namespace std;
string s;
int a,b,n,k;
stack<char> stk,check;
int change(char x){
	return x == '(' ? 2 : 3;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(!check.size()) check.push(s[i]);
		else if(check.top() == '(' && s[i] ==')'){
			check.pop();
		}
		else if(check.top() == '[' && s[i] ==']'){
			check.pop();
		}
		else check.push(s[i]);
	}
	if(check.size()){
		cout<<"0";
		return 0;
	}
	for(int i=0; i<s.size();i++){
		if(!stk.size()){
			stk.push(s[i]);
			a = !a ?  change(s[i]) : a+change(s[i]);
		}
		else{
			char top = stk.top();
			if(top == '(' && s[i] == ')'){
				b += a;
				if(s[i-1] !='(') b -= a;
				a = !(a-2) ? 0 : a/2;
				stk.pop();
			}
			else if(top == '[' && s[i] == ']'){
				b += a;
				if(s[i-1] != '[') b-=a;
				a = !(a-3) ? 0: a/3;
				stk.pop();
			}
			else{
				a = !a ? change(s[i]) : a*change(s[i]);
				stk.push(s[i]);
			}
		}
	}
	cout<<b<<'\n';
}
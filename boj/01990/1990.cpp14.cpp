#include <bits/stdc++.h>

using namespace std;
int a,b;
bool check(string s){
	for(int i=0; i<s.size()/2; i++) if(s[i] != s[s.size()-1-i]) return 0;
	return 1;
}
bool check2(int x){
	for(int i = 2; i*i<=x; i++) if(!(x%i)) return 0;
	return 1; 
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>a>>b;
	for(int i=a; i<=b; i++){
		string s = to_string(i);
		if(s.size() > 7) break;
		if(check(s) && check2(i)){
			cout<<i<<'\n';
		}
	}
	cout<<-1;
}
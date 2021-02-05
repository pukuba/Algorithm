#include <bits/stdc++.h>

using namespace std;
int n,m;
bool check(string s){
	int a=0,b=0;
	for(int i=0; i<s.size(); i++){
		if(s[i]=='a'||s[i]=='e'||s[i]=='u'||s[i]=='o'||s[i]=='i') a++;
		else b++;
	}
	return 1<=a && 2<=b;
}
void go(int stop,vector<char> &alpha,string s,int i){
	if(s.size()==stop){
		if(check(s)){
			cout<<s<<'\n';
		}
		return ;
	}
	if(i==alpha.size()) return ;
	go(stop,alpha,s+alpha[i],i+1);
	go(stop,alpha,s,i+1);
}
int main(){
	cin>>n>>m;
	vector<char> v(m);
	for(int i=0; i<m; i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	go(n,v,"",0);
	return 0;
}
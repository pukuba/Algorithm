#include <iostream>
#include <map>
#include <string>
#include <ctype.h>

using namespace std;
map<string,int> p1;
map<int,string> p2;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>s;
		p1.insert(make_pair(s,i));
		p2.insert(make_pair(i,s));
	}
	for(int i=0; i<m; i++){
		cin>>s;
		if(isalpha(s[0])){
			cout<<p1[s]<<'\n';
		}
		else{
			cout<<p2[stoi(s)]<<'\n';
		}
	}
} 
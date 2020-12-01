#include <bits/stdc++.h>

using namespace std;
int n;
char _map[66][66];
void f(int y,int x,int s){
	int cnt = 0;
	for(int i=y; i<y+s; i++){
		for(int j=x; j<x+s; j++){
			if(_map[i][j] == '0') cnt++;
		}
	}
	if(!cnt || cnt == s*s){
		if(cnt == s*s) cout<<0;
		if(!cnt) cout<<1;
		return; 
	}
	else{
		cout<<'(';
		f(y,x,s/2);
		f(y,x+s/2,s/2);
		f(y+s/2,x,s/2);
		f(y+s/2,x+s/2,s/2);
		cout<<')';
	}
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>_map[i][j];
    f(1,1,n);
}
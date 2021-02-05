#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n,t,dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
struct pos{
	int y,x,p,status=0;
}me;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>t;
	for(int i=1; i<=n; i++){
		int k;
		string s;
		cin>>k>>s;
		me.x += dx[me.status%4] * (k-me.p);
		me.y += dy[me.status%4] * (k-me.p);
		me.p = k;
		if(s == "right") me.status ++;
		else me.status+=3;
	}
	me.x += dx[me.status%4] * (t-me.p);
	me.y += dy[me.status%4] * (t-me.p);
	cout<<me.x<<' '<<me.y<<'\n';
}
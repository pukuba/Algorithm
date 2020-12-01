#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
ull d[222][222];
int t,x;
ull f(int x,int y){
	if(y < 0 || x < 0) return 0;
	if(x == y && !x) return 1;
	if(d[x][y] != -1) return d[x][y];
	return d[x][y] = f(x-1,y+1) + f(x,y-1);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	memset(d,-1,sizeof(d));
	while(1){
		cin>>x;
		if(!x) return 0;
		cout<<f(x,0)<<'\n';
	}
}
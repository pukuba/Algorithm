#include <bits/stdc++.h>

using namespace std;
long long n,m,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},_map[504][504],d[504][504];
bool in(int a,int b){ return 1<=a && a<=n && 1<=b && b<=m; }
long long dfs(int y,int x){
	if(y==n && x==m) return 1;
	if(!in(y,x)) return 0;
	if(d[y][x]!=-1) return d[y][x];
	long long &ret = d[y][x];
	ret=0;
	long long ans=0;
	for(int i=0; i<4; i++){
		int next_x=x+dx[i];
		int next_y=y+dy[i];
		if(_map[y][x]>_map[next_y][next_x]) ans+=dfs(next_y,next_x);
	}
	return ret=ans;
	
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	memset(d,-1,sizeof(d));
	cin>>n>>m;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
	cout<<dfs(1,1)<<'\n';
}
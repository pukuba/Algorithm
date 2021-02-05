#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<=n; i++)
using namespace std;
int n,m,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},cnt,ans=0;
bool _map[101][101],check[101][101];
bool in(int a,int b){
	return (1<=a && a<=n && 1<=b && b<=m);
}
void dfs(int y,int x){
	rep(i,0,3){
		int next_x=x+dx[i],next_y=y+dy[i];
		if(in(next_y,next_x) && !check[next_y][next_x] && !_map[next_y][next_x]){
			check[next_y][next_x]=1;
			dfs(next_y,next_x);
		}
		else if(in(next_y,next_x) && !check[next_y][next_x] && _map[next_y][next_x]){
			check[next_y][next_x]=1;
			_map[next_y][next_x]=0;
		}
	}
	return;
}
main(){
	cin>>n>>m;
	rep(i,1,n) rep(j,1,m){
		cin>>_map[i][j];
		if(_map[i][j]) ans++;
	}
	while(1){
		int real_ans=0;
		cnt++;
		memset(check,false,sizeof(check));
		dfs(1,1);
		rep(i,1,n) rep(j,1,m) if(_map[i][j]) real_ans++;
		if(!real_ans){
			cout<<cnt<<'\n';
			cout<<ans<<'\n';
			return 0;
		}
		ans=real_ans;
	}
}
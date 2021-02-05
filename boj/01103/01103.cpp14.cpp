#include <bits/stdc++.h>

using namespace std;
int n,m,d[51][51];
char _map[51][51];
bool check[51][51];
bool in(int a,int b){
	return 1<=a && a<=n && 1<=b && b<=m;
}
int dfs(int y,int x){
	if(_map[y][x]=='H' || !in(y,x)) return 0;
	int here=(int)_map[y][x]-'0';
	int dx[4]={here*-1,0,here,0};
	int dy[4]={0,here*-1,0,here};
	if(check[y][x]){
		cout<<"-1"<<'\n';
		exit(0);
	}
	if(d[y][x]!=-1) return d[y][x];
	check[y][x]=1;
	for(int i=0; i<4; i++){
		int next_x=x+dx[i];
		int next_y=y+dy[i];
		d[y][x]=max(d[y][x],dfs(next_y,next_x)+1);
	}
	check[y][x]=0;
	return d[y][x];
}
main(){
	memset(d,-1,sizeof(d));
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>_map[i][j];
		}
	}
	cout<<dfs(1,1);
}
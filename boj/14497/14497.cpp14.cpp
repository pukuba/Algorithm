#include <bits/stdc++.h>

using namespace std;
int n,m,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},arr[301][301],ans=0;;
bool check[301][301];
int in(int a,int b){
	return (1 <= a && a <= n && 1 <= b && b <= m);
}
struct point{
	int y,x;
};
int main(){
	cin>>n>>m;
	int s_x,s_y,e_x,e_y;
	cin>>s_y>>s_x>>e_y>>e_x;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			char x;
			cin>>x;
			if(x=='#') arr[i][j]=1;
			else if(x=='1') arr[i][j]=1;
			else if(x=='0') arr[i][j]=0;
		}
	}
	queue<point> q;
	while(1){
	memset(check,0,sizeof(check));
	q.push({s_y,s_x});
	check[s_y][s_x]=true;
	while(!q.empty()){
		int cur_x=q.front().x;
		int cur_y=q.front().y;
		if(cur_x==e_x && cur_y==e_y){
			cout<<ans<<'\n';
			return 0;
		}
		q.pop();
		for(int i=0; i<4; i++){
			int next_x=cur_x+dx[i];
			int next_y=cur_y+dy[i];
			if(in(next_y,next_x) && !check[next_y][next_x] && arr[next_y][next_x]==1){
				check[next_y][next_x]=true;
				arr[next_y][next_x]=0;
			}
			else if(in(next_y,next_x) && !check[next_y][next_x] && arr[next_y][next_x]==0){
				check[next_y][next_x]=true;
				q.push({next_y,next_x});
			}
		}
	}
	ans++;	
	}
}

#include <bits/stdc++.h>

using namespace std;
int n,m,k,bfs[11][1001][1001];
int arr[1001][1001];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
bool in(int a,int b){
	return (1 <= a && a <= n && 1 <= b && b <= m);
}
struct point{
	int y,x,wall;
};
int main(){
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	queue<point> q;
	q.push({1,1,0});
	bfs[0][1][1]=0;
	while(!q.empty()){
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		int cur_wall = q.front().wall;
		q.pop();
		if(cur_x == m && cur_y == n){
			cout<<bfs[cur_wall][cur_y][cur_x]+1<<'\n';
			return 0;
		}
		for(int i=0; i<4; i++){
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if(in(next_y,next_x) && !bfs[cur_wall][next_y][next_x]){
				if(arr[next_y][next_x]==1 && cur_wall < k){
					bfs[cur_wall+1][next_y][next_x]=bfs[cur_wall][cur_y][cur_x]+1;
					q.push({next_y,next_x,cur_wall+1});
				}
				if(arr[next_y][next_x]==0){
					bfs[cur_wall][next_y][next_x]=bfs[cur_wall][cur_y][cur_x]+1;
					q.push({next_y,next_x,cur_wall});
				}
			}
		}
	}
	cout<<"-1"<<'\n';
}
#include <bits/stdc++.h>

using namespace std;
int n,m,dx[4]={0,-1,0,1},dy[4]={1,0,-1,0},dist[105][105],_map[101][101];;
struct pos{
	int y,x,use;
	bool operator < (const pos &a) const{
		return use > a.use;
	}
};
bool in(int a,int b){ return 1<=a && a<=n && 1<=b && b<=m;}
priority_queue<pos> pq;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>m>>n;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
		char x;
		cin>>x;
		_map[i][j] = x == '1';
	}
	memset(dist,0x3f,sizeof dist);
	dist[1][1] = 0;
	pq.push({1,1,0});
	while(pq.size()){
		int y = pq.top().y;
		int x = pq.top().x;
		int use = pq.top().use;
		pq.pop();
		if(y == n && x == m){
			cout<<use<<'\n';
			return 0;
		}
		if(dist[y][x] != use) continue;
		for(int i=0; i<4; i++){
			int next_x = dx[i] + x, next_y = dy[i] + y;
			if(!in(next_y,next_x)) continue;
			if(dist[next_y][next_x] > dist[y][x] + _map[next_y][next_x]){
				dist[next_y][next_x] = dist[y][x] + _map[next_y][next_x];
				pq.push({next_y,next_x,dist[next_y][next_x]});
			}
		}
	}
}
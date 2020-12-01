#include <bits/stdc++.h>

using namespace std;
int n,m,ans,dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
char _map[1021][1021];
struct pos{int y,x,stat,cnt;};
queue<pos> q;
bool check[1022][1022][3];
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
	q.push({1,1,0,1});
	check[1][1][0] = 1;
	while(q.size()){
		pos here = q.front();
		q.pop();
		if(here.y == n && here.x == m){
			cout<<here.cnt<<'\n';
			return 0;
		}
		for(int i=0; i<4; i++){
			int next_y = here.y + dy[i],next_x = here.x + dx[i];
			if(_map[next_y][next_x] == '0' && !check[next_y][next_x][here.stat]){
				q.push({next_y,next_x,here.stat,here.cnt+1});
				check[next_y][next_x][here.stat] = 1;
			} 
			if(!here.stat && _map[next_y][next_x] == '1' && !check[next_y][next_x][1]){
				check[next_y][next_x][1] = 1;
				q.push({next_y,next_x,here.stat+1,here.cnt+1});
			}
		}
	}	
	cout<<-1<<'\n';
}
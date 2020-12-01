#include <bits/stdc++.h>

using namespace std;
int n,m,ans,dx[8]={0,-1,0,1,-1,-1,1,1},dy[8]={-1,0,1,0,1,-1,-1,1},_map[1021][1021],_e,l;
struct pos{int y,x,cnt;};
queue<pos> q;
bool check[1022][1022];
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	cin>>m>>n;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
		cin>>_map[i][j];
		if(_map[i][j] == 1){
			q.push({i,j,0});
			check[i][j] = 1;
		}
	}	
	while(q.size()){
		pos here = q.front();
		l = max(l,here.cnt);	
		q.pop();
		for(int i = 0; i<4; i++){
			int next_x = here.x + dx[i], next_y = here.y + dy[i];
			if(in(next_y,next_x) && !check[next_y][next_x] && !_map[next_y][next_x]){
				_map[next_y][next_x] = 1;
				check[next_y][next_x] = 1;
				q.push({next_y,next_x,here.cnt+1});
			}
		}
	}
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) {
		if(_map[i][j] == 0){
			cout<<-1;
			return 0;
		}
	}
	cout<<l;
}
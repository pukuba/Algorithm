#include <bits/stdc++.h>
#define  rep(i,x,n) for(int i=x; i<=n; i++)
using namespace std;
int n,m,sx,sy,ex,ey,cnt=1,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
char _map[1501][1501];
bool check[1501][1501],l_check[1501][1501];
bool in(int a,int b){
	return 1<=a && a<=n && 1<=b && b<=m;
}
main(){
	cin>>n>>m;
	queue<pair<int,int> > q;
	queue<pair<int,int> > temp;
	queue<pair<int,int> > l;
	bool next=false;
	rep(i,1,n) rep(j,1,m){
		cin>>_map[i][j];
		if(_map[i][j]=='.' || _map[i][j]=='L'){
			q.push({i,j});
			check[i][j]=true;
		}
		if(_map[i][j]=='L' && !next){
			next=true;
			sx=j;sy=i;
			_map[i][j]='.';
			l_check[sy][sx]=true;
			l.push({i,j});
		}
		else if(_map[i][j]=='L' && next){
			_map[i][j]='.';
			ex=j,ey=i;
		}
	}
	while(1){
		while(!l.empty()){
			int cur_x=l.front().second;
			int cur_y=l.front().first;
			if(cur_y==ey && cur_x==ex){
				cout<<cnt-1<<'\n';
				return 0;
			}
			l.pop();
			rep(i,0,3){
				int next_x=cur_x+dx[i];
				int next_y=cur_y+dy[i];
				if(!in(next_y,next_x)) continue;
				if(!l_check[next_y][next_x] && _map[next_y][next_x]=='X'){
					l_check[next_y][next_x]=1;
					temp.push({next_y,next_x});
				}
				if(!l_check[next_y][next_x] && _map[next_y][next_x]=='.'){
					l_check[next_y][next_x]=true;
					l.push({next_y,next_x});
				}
			}
		}
		while(!temp.empty()){
			int xx=temp.front().second;
			int yy=temp.front().first;
			l.push({yy,xx});
			temp.pop();
		}
		while(!q.empty()){
			int cur_x=q.front().second;
			int cur_y=q.front().first;
			q.pop();
			rep(i,0,3){
				int next_x=cur_x+dx[i];
				int next_y=cur_y+dy[i];
				if(!in(next_y,next_x)) continue;
				if(!check[next_y][next_x] && _map[next_y][next_x]=='X'){
					_map[next_y][next_x]='.';
					temp.push({next_y,next_x});
					check[next_y][next_x]=1;
				}
				if(!check[next_y][next_x] && _map[next_y][next_x]=='.'){
					check[next_y][next_x]=1;
					q.push({next_y,next_x});
				}
			}
		}
		while(!temp.empty()){
			int xx=temp.front().second;
			int yy=temp.front().first;
			q.push({yy,xx});
			temp.pop();
		}
		
		cnt++;
	}
}
#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<=n; i++)
using namespace std;
char _map[1001][1001];
bool check[1001][1001]; 
int n,m,cnt[1001][1001],sx,sy,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
struct point{
	int y,x,cnt;
};
bool in(int a,int b){
	return 1<=a && a<=n && 1<=b && b<=m;
}
main(){
	memset(cnt,-1,sizeof(cnt));
	cin.tie(0),cout.tie(0);
	queue<point> q;
	cin>>n>>m;
	rep(i,1,n) rep(j,1,m){
		cin>>_map[i][j];
		if(_map[i][j]=='F'){
			_map[i][j]='.';
			cnt[i][j]=0;
			check[i][j]=1;
			q.push({i,j,0});
		}
		if(_map[i][j]=='J'){
			_map[i][j]='.';
			sx=j;
			sy=i;
		}
	}
	while(!q.empty()){
		int cur_x=q.front().x;
		int cur_y=q.front().y;
		int cur_cnt=q.front().cnt;
		q.pop();
		for(int i=0; i<4; i++){
			int next_x=cur_x+dx[i];
			int next_y=cur_y+dy[i];
			int next_cnt=cur_cnt+1;
			if(!in(next_y,next_x)) continue;
			if(!check[next_y][next_x] && _map[next_y][next_x]=='.'){
				cnt[next_y][next_x]=next_cnt;
				check[next_y][next_x]=true;
				q.push({next_y,next_x,next_cnt});
			}
		}
	}
	memset(check,false,sizeof(check));
	q.push({sy,sx,0});
	check[sy][sx]=1;
	while(!q.empty()){
		int cur_x=q.front().x;
		int cur_y=q.front().y;
		int cur_cnt=q.front().cnt;
		if(cur_x==m || cur_y==n || cur_x==1 || cur_y==1){
			cout<<cur_cnt+1<<'\n';
			return 0;
		}
		q.pop();
		for(int i=0; i<4; i++){
			int next_x=cur_x+dx[i];
			int next_y=cur_y+dy[i];
			int next_cnt=cur_cnt+1;
			if(!in(next_y,next_x));
			if(!check[next_y][next_x] && _map[next_y][next_x]=='.' && ((cnt[next_y][next_x]==-1)||next_cnt<cnt[next_y][next_x]) ){
				check[next_y][next_x]=true;
				q.push({next_y,next_x,next_cnt});
			}
		}
	}
	cout<<"IMPOSSIBLE \n";
}

#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<=n; i++)

using namespace std;
int t,n,m,arr[1001][1001],sx,sy,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
char _map[1001][1001];
bool go[1001][1001];
struct point{
	int y,x,cnt;
};
bool in(int a,int b){
	return 1<=a && a<=n && 1<=b && b<=m; 
}
main(){
	cin>>t;
	while(t--){
		memset(go,false,sizeof(go));
		memset(arr,-1,sizeof(arr));
		memset(_map,false,sizeof(_map));
		queue<pair<int,int> > q;
		queue<point> run;
		cin>>m>>n;
		rep(i,1,n) rep(j,1,m){
			cin>>_map[i][j];
			if(_map[i][j]=='@') sy=i,sx=j;
			if(_map[i][j]=='*'){
				arr[i][j]=0;
				q.push({i,j});
			}
		}
		while(!q.empty()){
			int cur_y=q.front().first;
			int cur_x=q.front().second;
			q.pop();
			rep(i,0,3){
				int next_y=cur_y+dy[i];
				int next_x=cur_x+dx[i];
				if(!in(next_y,next_x)) continue;
				if(arr[next_y][next_x]==-1 && _map[next_y][next_x]!='#'){
					arr[next_y][next_x]=arr[cur_y][cur_x]+1;
					q.push({next_y,next_x});
				}
			}
		}
		run.push({sy,sx,0});
		go[sy][sx]=true;
		bool frint=false;
		while(!run.empty()){
			int cur_y=run.front().y;
			int cur_x=run.front().x;
			int cur_cnt=run.front().cnt;
			if(cur_y==n || cur_y==1 || cur_x==m || cur_x==1){
				cout<<cur_cnt+1<<'\n';
				frint=true;
				break;
			}
			run.pop();
			rep(i,0,3){
				int next_y=cur_y+dy[i];
				int next_x=cur_x+dx[i];
				int next_cnt=cur_cnt+1;
				if(!in(next_y,next_x)) continue;
				if(!go[next_y][next_x] && _map[next_y][next_x]!='#' && (arr[next_y][next_x]>next_cnt || arr[next_y][next_x]==-1)){
					go[next_y][next_x]=true;
					run.push({next_y,next_x,next_cnt});
				}
			}
		}
		if(!frint) cout<<"IMPOSSIBLE\n";
	}
}
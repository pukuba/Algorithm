#include <bits/stdc++.h>

using namespace std;
struct point{
	int y,x,cnt;
};
char arr[51][51];
int map1[51][51],map2[51][51],ex,ey,ss,se,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},n,m;
bool in(int a,int b){
	return (1<=a && a<=n && 1<=b && b<=m);
}
int main(){
	cin>>n>>m;
	queue<point> q;
	queue<point> q2;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>arr[i][j];
			if(arr[i][j]=='*'){
				map1[i][j]=-2;
				map2[i][j]=0;
				q.push({i,j,0});
			}
			if(arr[i][j]=='.'){
				map2[i][j]=-1;
				map1[i][j]=-1;
			}
			if(arr[i][j]=='X'){
				map2[i][j]=-2;
				map1[i][j]=-2;
			}
			if(arr[i][j]=='D'){
				ex=j;
				ey=i;
				map1[i][j]=-2;
				map2[i][j]=-2;
			}
			if(arr[i][j]=='S'){
				ss=i;
				se=j;
				map2[i][j]=-5;
				map1[i][j]=0;
				q2.push({i,j,0});
			}
		}
	}
	for(int i=0; i<4; i++){
		int next_y=ss+dy[i];
		int next_x=se+dx[i];
		if(in(next_y,next_x) && arr[next_y][next_x]=='D'){
			cout<<1<<'\n';
			return 0;
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
			if(in(next_y,next_x)&& map2[next_y][next_x]==-1){
				map2[next_y][next_x]=next_cnt;
				q.push({next_y,next_x,next_cnt});
			}
		}
	}
	while(!q2.empty()){
		int cur_x=q2.front().x;
		int cur_y=q2.front().y;
		int cur_cnt=q2.front().cnt;
		q2.pop();
		for(int i=0; i<4; i++){
			int next_x=cur_x+dx[i];
			int next_y=cur_y+dy[i];
			int next_cnt=cur_cnt+1;
			if(in(next_y,next_x) && map1[next_y][next_x]==-1){
				map1[next_y][next_x]=next_cnt;
				q2.push({next_y,next_x,next_cnt});
			}
		}
	}
	vector<int> ans;
	for(int i=0; i<4; i++){
		if(in(ey+dy[i],ex+dx[i]) && map1[ey+dy[i]][ex+dx[i]]<map2[ey+dy[i]][ex+dx[i]] || map1[ey+dy[i]][ex+dx[i]]>=0 && map2[ey+dy[i]][ex+dx[i]]==-1){
			if(map1[ey+dy[i]][ex+dx[i]]!=-1) ans.push_back(map1[ey+dy[i]][ex+dx[i]]);
		}
	}
	if(ans.size()==0){
		cout<<"KAKTUS";
		return 0;
	}
	sort(ans.begin(),ans.end());
	cout<<ans[0]+1<<'\n';
	return 0;
}
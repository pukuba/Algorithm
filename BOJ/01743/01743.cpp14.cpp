#include <bits/stdc++.h>

using namespace std;

int arr[101][101],ans=0,dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},n,m,t,cnt=2;
struct point{
	int y,x,cnt;
};
bool in(int a,int b){
	return (1<=a && a<=n && 1<=b && b<=m);
}
int main(){
	cin>>n>>m>>t;
	memset(arr,-1,sizeof(arr));
	for(int i=0; i<t; i++){
		int x,y;
		cin>>x>>y;
		arr[x][y]=0;
	}
	queue<point> q;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(arr[i][j]==0){
				cnt++;
				arr[i][j]=cnt;
				q.push({i,j,cnt});
				while(!q.empty()){
					int cur_x=q.front().x;
					int cur_y=q.front().y;
					q.pop();
					for(int i=0; i<4; i++){
						int next_x=cur_x+dx[i];
						int next_y=cur_y+dy[i];
						if(in(next_y,next_x) && arr[next_y][next_x]==0){
							arr[next_y][next_x]=cnt;
							q.push({next_y,next_x,cnt});
						}
					}
				}
			}
		}
	}
	int ans_check[10001]={0,};
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(arr[i][j]!=-1){
				ans_check[arr[i][j]]+=1;
				ans=max(ans_check[arr[i][j]],ans);
			}
		}
	}
	cout<<ans<<'\n';
}
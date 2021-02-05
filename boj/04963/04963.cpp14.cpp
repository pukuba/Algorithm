#include <bits/stdc++.h>

using namespace std;
int n,m,ans,dx[8]={0,-1,0,1,-1,-1,1,1},dy[8]={-1,0,1,0,1,-1,-1,1};
queue<pair<int,int> > q;
bool _map[55][55],check[55][55];
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	while(1){
		cin>>m>>n;
		if(n == 0 && m == 0) return 0;
		memset(_map,0,sizeof(_map));
		memset(check,0,sizeof(check));
		ans = 0;
		for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin>>_map[i][j];
		for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
			if(!check[i][j] && _map[i][j]){
				ans++;
				q.push({i,j});
				check[i][j] = 1;
				while(q.size()){
					int here_y = q.front().first,here_x = q.front().second;
					q.pop();
					for(int i=0; i<8; i++){
						int next_y = here_y + dy[i],next_x = here_x + dx[i];
						if(in(next_y,next_x) && !check[next_y][next_x] && _map[next_y][next_x]){
							check[next_y][next_x] = 1;
							q.push({next_y,next_x});
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	
}
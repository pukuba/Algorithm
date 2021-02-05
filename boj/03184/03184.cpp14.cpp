#include <bits/stdc++.h>

using namespace std;
int n,m,v,o,dx[4]={0,-1,0,1},dy[4]={1,0,-1,0};
char _map[255][255];
bool check[255][255];
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
		cin>>_map[i][j];
		v += _map[i][j] == 'v';
		o += _map[i][j] == 'o';
	}
	for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
		if(!check[i][j] && _map[i][j] != '#'){
			queue<pair<int,int> > q;
			int c1 = 0, c2 = 0;
			q.push({i,j});
			check[i][j] = 1;
			while(q.size()){
				int y = q.front().first, x = q.front().second;
				c1 += _map[y][x] == 'o',c2 += _map[y][x] == 'v';
				q.pop();
				for(int k=0; k<4; k++){
					int ny = y + dy[k], nx = x + dx[k];
					if(in(ny,nx) && !check[ny][nx] && _map[ny][nx] != '#'){
						check[ny][nx] = 1;
						q.push({ny,nx});
					}
				}
			}
			if(c1 <= c2) o -= c1;
			else v -= c2;
		}
	}
	cout<<o<<' '<<v<<'\n';
}
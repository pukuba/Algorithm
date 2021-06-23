#include <bits/stdc++.h>

using namespace std;
int a[66][66],line[66][66],n,dx[4]={0,-1,0,1},dy[4]={1,0,-1,0},ans=1e9;
bool in(int x,int y){return 1<=x && x<=n && 1<=y && y<=n;}
void dfs(int x,int y){
	if(line[x][y] == 5) return;
	line[x][y] = 5;
	for(int i=0; i<4; i++){
		int nx = x+dx[i], ny = y+dy[i];
		if(!in(nx,ny) || line[nx][ny] == 5) continue;
		dfs(nx,ny);
	}
}
void go(int x,int y,int d1,int d2){
	for(int i=0; i<=d1; i++){
		line[x + i][y - i] = 5;
	}
	for(int i=0; i<=d2; i++){
		line[x + i][y + i] = 5;
	}
	for(int i=0; i<=d2; i++){
		line[x+d1+i][y-d1+i] = 5;
	}
	for(int i=0; i<=d1; i++){
		line[x+d2+i][y+d2-i] = 5;
	}
	for(int i=1; i<=n; i++){
		int cnt = 0;
		for(int j=1; j<=n; j++){
			if(line[i][j] == 5) cnt++;
			if(cnt == 2){
				dfs(i,j-1);
				break;
			}
		}
	}
	for(int r=1; r<=n; r++){
		for(int c=1; c<=n; c++){
			if(r < x+d1 && c<=y && !line[r][c]) line[r][c] = 1;
			if(r <= x+d2 && y < c && !line[r][c]) line[r][c] = 2;
			if(x+d1<=r && c<y-d1+d2 && !line[r][c]) line[r][c] = 3;
			if(x+d2 < r && y-d1+d2 <= c && !line[r][c]) line[r][c] = 4;
		}
	}
}
int cal(){
	vector<int> v(5);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			v[line[i][j]-1] += a[i][j];
		}
	}
	sort(v.begin(),v.end());
	return v.back() - v.front();
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>a[i][j];
	for(int x=1; x<=n; x++){
		for(int y=1; y<=n; y++){
			for(int d1=1; d1<=n; d1++){
				for(int d2=1; d2<=n; d2++){
					if(x < x+d1+d2 && x+d1+d2 <= n && 1 <= y-d1 && y-d1 < y && y < y+d2 && y+d2 <= n){
						memset(line, 0, sizeof(line));
						go(x,y,d1,d2);
						ans = min(ans, cal());
					}	
				}
			}
		}
	}
	cout<<ans<<'\n';
}
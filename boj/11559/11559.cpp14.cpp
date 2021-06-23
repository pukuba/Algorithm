#include <bits/stdc++.h>

using namespace std;
int n=12, m=6, dx[4]={0,-1,0,1},dy[4]={1,0,-1,0},boom,ed;
char _map[14][8],tmp[14][8];
bool check[14][8];
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
void dfs(int y,int x){
    boom++;
    check[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(!in(ny,nx) || check[ny][nx]) continue;
        if(_map[y][x] == _map[ny][nx]) dfs(ny,nx);
    }
}
void wise(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(check[i][j]){
                _map[i][j] = '.';
                ed++;
            }
        }
    }
}
void down(){
    for(int i=1; i<=m; i++){
        vector<char> v;
        for(int j=n; j>=1; j--){
            if(_map[j][i] != '.'){
                v.push_back(_map[j][i]);
            }
        }
        for(int j=0; j<v.size(); j++) _map[n-j][i] = v[j];
        for(int j=n-v.size(); j>=1; j--) _map[j][i] = '.';
    }
}
void cp(){for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) tmp[i][j] = _map[i][j];}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>_map[i][j];
        }
    }
    for(int t=1; t<=100; t++){
    	cp();
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(!check[i][j] && _map[i][j] != '.'){
                    dfs(i,j);
                    if(boom >= 4){
                        wise();
                    }
                    memset(check, 0, sizeof(check));
                    boom = 0;
                }
            }
        }
        down();
        bool flg = false;
        for(int i=1; i<=n; i++){
        	for(int j=1; j<=m; j++){
        		flg |= _map[i][j] != tmp[i][j];
			}
		}
		if(!flg){
			cout<<t-1;
			return 0;
		}
    }
}
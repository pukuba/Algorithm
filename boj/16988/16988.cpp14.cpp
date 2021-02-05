#include <bits/stdc++.h>

using namespace std;
using pi = pair<int,int>;
int arr[22][22],n,m,ans,tmp[22][22],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool check[22][22];
vector<pi> v;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=m;}
int cal(pi a,pi b){
    memset(check, 0, sizeof check);
    memset(tmp, 0, sizeof tmp);
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) tmp[i][j] = arr[i][j];
    tmp[a.first][a.second] = 1;
    tmp[b.first][b.second] = 1;
    int ret = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(tmp[i][j] == 2 && !check[i][j]){
                queue<pi> q;
                int sz = 1;
                bool flag = true;
                check[i][j] = 1;
                q.push({i,j});
                while(q.size()){
                    auto [y,x] = q.front();
                    q.pop();
                    for(int k=0; k<4; k++){
                        int ny = y + dy[k], nx = x + dx[k];
                        if(!in(ny,nx)) continue;
                        if(check[ny][nx]) continue;
                        if(tmp[ny][nx] == 2){
                            q.push({ny,nx});
                            sz++;
                            check[ny][nx] = 1;
                        }
                        if(tmp[ny][nx] == 0){
                            flag = false;
                        }
                    }
                }
                if(flag) ret += sz;
            }
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
            if(!arr[i][j]){
                v.push_back({i,j});
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            ans = max(ans, cal(v[i],v[j]));
        }
    }
    cout<<ans<<'\n';
}
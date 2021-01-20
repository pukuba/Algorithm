#include <bits/stdc++.h>

using namespace std;
int n,dist[55][55],ans=1e9,sy,sx,cnt,dx[8]={1,0,-1,0,1,1,-1,-1},dy[8]={0,1,0,-1,1,-1,-1,1};
char _map[55][55];
set<int> s;
bool check[55][55];
vector<int> v;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=n;}
bool can(int low,int high){
    queue<pair<int,int> > q;
    if(low <= dist[sy][sx] && dist[sy][sx] <= high) q.push({sy,sx});
    else return 0;
    int p = 0;
    memset(check,0,sizeof check);
    check[sy][sx] = 1;
    while(q.size()){
        auto[y,x] = q.front();
        q.pop();
        for(int i=0; i<8; i++){
            int ny = y + dy[i], nx = x + dx[i];
            if(!in(ny,nx) || check[ny][nx] || !(low<=dist[ny][nx] && dist[ny][nx]<=high)) continue;
            check[ny][nx] = 1;
            if(_map[ny][nx] == 'K') p++;
            q.push({ny,nx});
        }
    }
    return p == cnt;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        cin>>_map[i][j];
        if(_map[i][j] == 'P') sy = i, sx = j;
        if(_map[i][j] == 'K') cnt++;
    }
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        cin>>dist[i][j];
        if(!s.count(dist[i][j])){
            v.push_back(dist[i][j]);
            s.insert(dist[i][j]);
        }
    }
    sort(v.begin(),v.end());
    for(int i : s){
        int from = 0,to = v.size()-1,go = 0;
        while(from <= to){
            int mid = from + to >> 1;
            if(can(i,v[mid])){
                to = mid - 1;
                ans = min(ans,abs(i-v[mid]));
            } else from = mid + 1;
        }
    }
    cout<<ans<<'\n';
}
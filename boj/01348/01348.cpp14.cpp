#include <bits/stdc++.h>

using namespace std;
struct point{int y,x,cnt;};
vector<pair<int,int>> can[2555],start;
vector<int> adj[2555];
int n,m,car_id,parking_id,_map[53][53],dx[4]={0,-1,0,1},dy[4]={-1,0,1,0},_min=1e9,_max,ans=-1,b[2555],cnt;
bool bfs_check[53][53],check[2555];
bool in(int a,int b){
    if(a < 1 || a > n || b < 1 || b > m) return false;
    return _map[a][b] != -1;
}
bool dfs(int here){
    check[here] = true;
    for(int next : adj[here]){
        if(b[next] == -1 || !check[b[next]] && dfs(b[next])){
            b[next] = here;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        char x;
        cin>>x;
        if(x == 'X') _map[i][j] = -1;
        if(x == '.') _map[i][j] = 0;
        if(x == 'C') start.push_back({i,j});
        if(x == 'P') _map[i][j] = ++parking_id;
    }
    for(int go = 0; go<start.size(); go++){
        memset(bfs_check,false,sizeof(bfs_check));
        bfs_check[start[go].first][start[go].second] = true;
        queue<point> q;
        q.push({start[go].first,start[go].second,0});
        while(q.size()){
            auto[here_y,here_x,here_cnt] = q.front();
            q.pop();
            if(_map[here_y][here_x] > 0){
                can[go+1].push_back({_map[here_y][here_x],here_cnt});
                _min = min(_min,here_cnt);
                _max = max(_max,here_cnt);
            }
            for(int i=0; i<4; i++){
                int next_x = dx[i] + here_x;
                int next_y = dy[i] + here_y;
                if(in(next_y,next_x) && !bfs_check[next_y][next_x]){
                    bfs_check[next_y][next_x] = true;
                    q.push({next_y,next_x,here_cnt+1});
                }
            }
        }
    }
    while(_min <= _max){
        cnt=0;
        int mid = _min + _max >> 1;
        for(int i=1; i<=start.size(); i++) adj[i].clear();
        for(int i=1; i<=start.size(); i++){
            for(pair<int,int> info : can[i]) if(info.second <= mid) adj[i].push_back(info.first);
        }
        memset(b,-1,sizeof(b));
        for(int i=1; i<=start.size(); i++){
            memset(check,false,sizeof(check));
            if(dfs(i)) cnt++;
        }
        if(cnt == start.size()){
            ans = mid;
            _max = mid - 1;
        }
        else _min = mid + 1;
    }
    if(!start.size()) cout<<0;
    else cout<<ans;
}
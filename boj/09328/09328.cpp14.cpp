#include <bits/stdc++.h>

using namespace std;
int t,n,m,dx[4]={0,1,0,-1},dy[4]={-1,0,1,0},ans,temp;
char _map[104][104];
string have;
queue<pair<int,int> > q;
bool check[104][104],keys[30];
void setting(){
    ans = 0;
    temp = 0;
    have = "";
    while(q.size()) q.pop();
    memset(_map,0,sizeof _map);
    memset(check,0,sizeof check);
    memset(keys,0,sizeof keys);
    for(int i=1; i<=n+2; i++) _map[i][1] = _map[i][m+2] = '.';
    for(int i=1; i<=m+2; i++) _map[1][i] = _map[n+2][i] = '.';
}
bool in(int a,int b){return 1<=a && a<=n+2 && 1<=b && b<=m+2;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n>>m;
        setting();
        //for(int i=1; i<=n+2; i++,puts("")) for(int j=1; j<=m+2; j++) cout<<(_map[i][j] == '.' ? "." : " ");
        for(int i=2; i<=1+n; i++) for(int j=2; j<=1+m; j++) cin>>_map[i][j];
        cin>>have;
        if(have != "0") for(char c : have) keys[c-'a'] = 1;
        while(1){
            q.push({1,1});
            memset(check,false,sizeof check);
            check[1][1] = 1;
            temp = 0;
            while(q.size()){
                auto[here_y,here_x] = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int next_y = here_y + dy[i],next_x = here_x + dx[i];
                    if(!in(next_y,next_x) || check[next_y][next_x]) continue;
                    if(_map[next_y][next_x] == '.'){
                        check[next_y][next_x] = 1;
                        q.push({next_y,next_x});
                    }
                    else if(_map[next_y][next_x] == '$'){
                        ans++;
                        _map[next_y][next_x] = '.';
                        check[next_y][next_x] = 1;
                        q.push({next_y,next_x});
                    }
                    else if('a' <= _map[next_y][next_x] && _map[next_y][next_x] <= 'z'){
                        keys[_map[next_y][next_x]-'a'] = 1;
                        _map[next_y][next_x] = '.';
                        temp++;
                        check[next_y][next_x] = 1;
                        q.push({next_y,next_x});
                    }
                    else if('A' <= _map[next_y][next_x] && _map[next_y][next_x] <= 'Z' && keys[_map[next_y][next_x]-'A']){
                        _map[next_y][next_x] = '.';
                        check[next_y][next_x] = 1;
                        q.push({next_y,next_x});
                    }
                }
            }
            if(!temp) break;
        }
        cout<<ans<<'\n';
    }
}
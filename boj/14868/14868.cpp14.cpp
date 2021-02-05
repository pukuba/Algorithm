#include <bits/stdc++.h>

using namespace std;
int n,m,id[2020][2020],pk,dx[4]={0,-1,0,1},dy[4]={1,0,-1,0},ans,v;
bool check[2020][2020],one[2020][2020],can[105050];
queue<pair<int,int> > q,temp,o;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=n;}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1,x,y; i<=m; i++){
        cin>>x>>y;
        check[x][y] = 1;
        q.push({x,y});
        id[x][y] = i;
        if(i == 1){
            can[1] = true;
            v++;
            one[x][y] = 1;
            o.push({x,y});
        }
    }
    can[0] = 1;
    while(1){
        while(o.size()){
            auto[y,x] = o.front();
            o.pop();
            for(int i=0; i<4; i++){
                int next_x = x + dx[i],next_y = y + dy[i];
                if(in(next_y,next_x) && !check[next_y][next_x] && !one[next_y][next_x]){
                    one[next_y][next_x] = 1;
                    temp.push({next_y,next_x});
                }
                else if(in(next_y,next_x) && check[next_y][next_x] && !can[id[next_y][next_x]] && !one[next_y][next_x]){
                    one[next_y][next_x] = 1;
                    can[id[next_y][next_x]] = 1;
                    o.push({next_y,next_x});
                    v++;
                }
                else if(in(next_y,next_x) && check[next_y][next_x] && can[id[next_y][next_x]] && !one[next_y][next_x]){
                    one[next_y][next_x] = 1;
                    o.push({next_y,next_x});
                }
            }
        }
        if(v == m){
            cout<<ans;
            return 0;
        } ans++;
        while(temp.size()){
            o.push(temp.front());
            temp.pop();
        }
        while(q.size()){
            auto[y,x] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int next_x = x+dx[i],next_y= dy[i] + y;
                if(!in(next_y,next_x) || check[next_y][next_x]) continue;
                temp.push({next_y,next_x});
                check[next_y][next_x] = 1;
            }
        }
        while(temp.size()){
            q.push(temp.front());
            temp.pop();
        }
    }
}

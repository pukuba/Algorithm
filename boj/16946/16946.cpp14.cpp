#include <bits/stdc++.h>

using namespace std;
int _map[1001][1001],n,m,ans[1001][1001],dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},cmp_size,_id;
bool check[1001][1001],check1[1001][1001];
bool in(int a,int b){
    return 1 <= a && a <= n && 1 <= b && b <= m;
}
struct point{
    int y,x;
};
struct _key{
    int value,id;
};
void dfs(int y,int x){
    cmp_size++;
    for(int i=0; i<4; i++){
        int next_x=x+dx[i];
        int next_y=y+dy[i];
        if(!in(next_y,next_x)) continue;
        if(!check[next_y][next_x] && 0==_map[next_y][next_x]){
            check[next_y][next_x]=true;
            dfs(next_y,next_x);
        }
    }
}
_key comp[1001][1001];
int main(){
    queue<point> q;
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) scanf("%1d",&_map[i][j]);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(_map[i][j]==0 && !check[i][j]){
                _id++;
                cmp_size=0;
                check[i][j]=true;
                dfs(i,j);
                q.push({i,j});
                check1[i][j]=true;
                comp[i][j].id=_id;
                comp[i][j].value=cmp_size;
                while(!q.empty()){
                    int cur_x=q.front().x;
                    int cur_y=q.front().y;
                    q.pop();
                    for(int i=0; i<4; i++){
                        int next_y=cur_y+dy[i];
                        int next_x=cur_x+dx[i];
                        if(!in(next_y,next_x)) continue;
                        if(!check1[next_y][next_x] && _map[next_y][next_x]==0){
                            check1[next_y][next_x]=true;
                            comp[next_y][next_x].id=_id;
                            comp[next_y][next_x].value=cmp_size;
                            q.push({next_y,next_x});
                        }
                    }
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(_map[i][j]==1){
                ans[i][j]++;
                vector<int> ck;
                for(int k=0; k<4; k++){
                    int next_x=j+dx[k];
                    int next_y=i+dy[k];
                    if(!in(next_y,next_x)) continue;
                    ck.push_back(comp[next_y][next_x].id);
                }
                for(int k=0; k<4; k++){
                    bool plus_ans=false;
                    int next_x=j+dx[k];
                    int next_y=i+dy[k];
                    if(!in(next_y,next_x)) continue;
                    for(int ii=0; ii<ck.size(); ii++){
                        if(ck[ii] == comp[next_y][next_x].id){
                            plus_ans=true;
                            ck[ii]=2133122;
                        }
                    }
                    if(plus_ans==true) ans[i][j]+=comp[next_y][next_x].value;
                }
            }
        }
    }
    for(int i=1; i<=n; i++,cout<<'\n') for(int j=1; j<=m; j++) cout<<(ans[i][j])%10;
    
}

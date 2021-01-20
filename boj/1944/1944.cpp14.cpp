#include <bits/stdc++.h>

using namespace std;
int n,k,sx,sy,uf[2501],dx[4]={-1,1,0,0},dy[4]={0,0,-1,1},key[51][51],num=0;
char _map[51][51];
bool check[51][51];
struct point{int y,x,cnt;};
struct inf{int from,to,money;};
vector<inf> v;
vector<pair<int,int> > _key;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=n;}
int find(int a){
    if(uf[a]==a) return a;
    return uf[a]=find(uf[a]);
}
bool cmp(const inf &a,const inf &b){ return a.money<b.money;}
void merge(int a,int b){
    a=find(a);
    b=find(b);
    uf[a]=b;
}
int bfs(int y,int x,int start){
    int ret=1;
    memset(check,false,sizeof(check));
    queue<point> q;
    q.push({y,x,0});
    check[y][x]=1;
    while(!q.empty()){
        auto [y,x,cnt] = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int next_x=x+dx[i];
            int next_y=y+dy[i];
            int next_cnt=cnt+1;
            if(!in(next_y,next_x)) continue;
            if(!check[next_y][next_x] && _map[next_y][next_x]=='K'){
                check[next_y][next_x]=true;
                ret++;
                v.push_back({start,key[next_y][next_x],next_cnt});
                q.push({next_y,next_x,next_cnt});
            }
            if(!check[next_y][next_x] && _map[next_y][next_x]=='0'){
                check[next_y][next_x]=true;
                q.push({next_y,next_x,next_cnt});
            }
            if(ret==k+1) return ret;
        }
    }
    return ret;
}
int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        cin>>_map[i][j];
        if(_map[i][j]=='S'){
            sx=j;
            sy=i;
            _map[i][j]='K';
        }
        if(_map[i][j]=='K'){
            key[i][j]=num++;
            _key.push_back({i,j});
        }
    }
    for(auto i : _key){
        if(bfs(i.first,i.second,key[i.first][i.second]) != k+1){
            cout<<-1<<'\n';
            return 0;
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0; i<=k+1; i++) uf[i]=i;
    int idx=0,cnt=0,ans=0;
    while(cnt!=k){
        int cur_x=find(v[idx].from);
        int cur_y=find(v[idx].to);
        if(cur_x!=cur_y){
            merge(cur_y,cur_x);
            ans+=v[idx].money;
            cnt++;
        }
        idx++;
    }
    cout<<ans<<'\n';
}

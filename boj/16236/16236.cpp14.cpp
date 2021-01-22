#include <bits/stdc++.h>

using namespace std;
int arr[21][21],_time,_map[21][21],dx[4]={0,-1,0,1},dy[4]={-1,0,1,0},n;
int check[21][21];
pair<int,int> shark={2,0};
struct point{
    int y,x,cnt;
};
bool comp(point a,point b){
    if(a.cnt == b.cnt){
        if(a.y == b.y){
            return a.x < b.x;
        }
        return a.y < b.y;
    }
    return a.cnt<b.cnt;
}
vector<point> pt;
bool in(int a,int b){
    return (1<=a && a<=n && 1<=b && b<=n);
}
queue<point> q;
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++){
        cin>>_map[i][j];
        if(_map[i][j]==9){
            check[i][j]=true;
            q.push({i,j,0});
            _map[i][j] = 0;
        }
    }
    while(1){
        
        memset(check,0,sizeof(check));
        while(!q.empty()){
            auto [y,x,cnt] =q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int next_x=x+dx[i];
                int next_y=y+dy[i];
                int next_cnt=cnt+1;
                if(!in(next_y,next_x)) continue;
                if((_map[next_y][next_x]==0||_map[next_y][next_x]==shark.first) && !check[next_y][next_x]){
                    check[next_y][next_x]= check[y][x] + 1;
                    q.push({next_y,next_x,next_cnt});
                }
                if(_map[next_y][next_x]!=0 && _map[next_y][next_x]<shark.first && !check[next_y][next_x]){
                    pt.push_back({next_y,next_x,next_cnt});
                    check[next_y][next_x]= check[y][x] + 1;
                }
            }
        }
        if(!pt.size()) break;
        sort(pt.begin(),pt.end(),comp);
        auto[start_y,start_x,start_cnt]=pt[0];
        _map[start_y][start_x]=0;
        q.push({start_y,start_x,0});
        _time+=start_cnt;
        shark.second++;
        if(shark.first==shark.second){
            shark.first++;
            shark.second=0;
        }
        pt.clear();
    }
    cout<<_time<<'\n';
}

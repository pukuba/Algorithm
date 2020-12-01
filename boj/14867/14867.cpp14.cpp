#include <bits/stdc++.h>

using namespace std;
struct point{int _a,_b,cnt;};
int a,b,c,d;
set<pair<int,int> > s;
queue<point> q;
void go(pair<int,int> a,int cnt){
    point c={a.first,a.second,cnt};
    if(!s.count(a)) s.insert(a),q.push(c);
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>a>>b>>c>>d;
    go({0,0},0);
    while(!q.empty()){
        auto[cur_a,cur_b,cnt] = q.front();
        q.pop();
        if(cur_a==c && cur_b==d){
            cout<<cnt<<'\n';
            return 0;
        }
        int next_a=0,next_b=0;
        go({next_a,cur_b},cnt+1),go({cur_a,next_b},cnt+1);
        go({a,cur_b},cnt+1),go({cur_a,b},cnt+1);
        next_a=cur_a+cur_b,next_b=0;
        if(next_a>a){
            next_b=next_a-a;
            next_a=a;
        } go({next_a,next_b},cnt+1);
        next_b=cur_a+cur_b,next_a=0;
        if(next_b>b){
            next_a=next_b-b;
            next_b=b;
        } go({next_a,next_b},cnt+1);
    }
    cout<<-1<<'\n';
}

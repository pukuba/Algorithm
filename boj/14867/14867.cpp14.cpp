#include <bits/stdc++.h>

using namespace std;
int a,b,last_a,last_b;
set<pair<int,int> > s;
struct point{int a,b,cnt;};
queue<point> q;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a>>b>>last_a>>last_b;
    s.insert({0,0});
    q.push({0,0,0});
    while(!q.empty()){
        auto [cur_a,cur_b,cnt] = q.front();
        q.pop();
        if(cur_a==last_a && cur_b==last_b){
            cout<<cnt<<'\n';
            return 0;
        }
        int next_a=a;
        int next_b=b;
        auto it = s.find({next_a,cur_b});
        if(it == s.end()){
            s.insert({next_a,cur_b});
            q.push({next_a,cur_b,cnt+1});
        }
        it = s.find({cur_a,next_b});
        if(it == s.end()){
            s.insert({cur_a,next_b});
            q.push({cur_a,next_b,cnt+1});
        }
        next_a=next_b=0;
        it = s.find({next_a,cur_b});
        if(it == s.end()){
            s.insert({next_a,cur_b});
            q.push({next_a,cur_b,cnt+1});
        }
        it = s.find({cur_a,next_b});
        if(it == s.end()){
            s.insert({cur_a,next_b});
            q.push({cur_a,next_b,cnt+1});
        }
        next_a=cur_a+cur_b;
        next_b=0;
        if(next_a>a){
            next_b=next_a-a;
            next_a=a;
        }
        it = s.find({next_a,next_b});
        if(it == s.end()){
            s.insert({next_a,next_b});
            q.push({next_a,next_b,cnt+1});
        }
        next_b=cur_b+cur_a;
        next_a=0;
        if(next_b>b){
            next_a=next_b-b;
            next_b=b;
        }
        it = s.find({next_a,next_b});
        if(it == s.end()){
            s.insert({next_a,next_b});
            q.push({next_a,next_b,cnt+1});
        }
    }
    cout<<-1<<'\n';
}

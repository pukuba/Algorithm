#include <bits/stdc++.h>

using namespace std;
int a,b;
set<int> s;
queue<pair<int,int> > q;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>a>>b;
    s.insert(b);
    q.push({b,0});
    while(q.size()){
        auto[here,cnt] = q.front();
        q.pop();
        if(here <= 0) continue;
        if(here == a){
            cout<<cnt+1<<'\n';
            return 0;
        }
        if(here%10 == 1){
            q.push({here/10,cnt+1});
            s.insert(here/10);
        }
        if(~here&1){
            q.push({here/2,cnt+1});
            s.insert(here/2);
        }
    }
    cout<<-1<<'\n';
}
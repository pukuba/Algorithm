#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int> > v[(int)1e5+1];
bool check[1<<20];
int n,s,e, _max[(int)1e5 + 1];
int main(){
    cin>>n>>s>>e;
    for(int i=1; i<=n-1; i++){
        int from,go,weight;
        cin>>from>>go>>weight;
        v[from].push_back({go,weight});
        v[go].push_back({from,weight});
    }
    queue<pair<int,int> > q;
    q.push({s,0});
    check[s]=true;
    _max[s]  = 0;
    while(!q.empty()){
        auto [cur_x,dist] = q.front();
        if(cur_x == e){
            cout<<dist - _max[e]<<'\n';
            return 0;
        }
        q.pop();
        for(pair<int,int> i : v[cur_x]){
            int next_x = i.first;
            if(!check[next_x]){
                check[next_x] = true;
                _max[next_x] = max(i.second, _max[cur_x]);
                q.push({next_x,dist + i.second});
            }
        }
    }
}

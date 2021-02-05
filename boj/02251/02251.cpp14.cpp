#include <bits/stdc++.h>

using namespace std;
int bot[4];
pair<int,int> go[6]={{0,1},{0,2},{1,2},{1,0},{2,0},{2,1}};
bool check[222][222][222];
vector<int> ans;
vector<int> sw(vector<int> temp,int from,int to){
    int f = temp[from];
    int t = temp[to];
    if(t + f <= bot[to]) temp[to] = t+f,temp[from]=0;
    if(t + f > bot[to]){
        temp[to] = bot[to];
        temp[from] = t+f-bot[to];
    }
    return temp;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>bot[0]>>bot[1]>>bot[2];
    queue<vector<int>> q;
    q.push({0,0,bot[2]});
    check[0][0][bot[2]] = 1;
    while(q.size()){
        vector<int> v = q.front();
        q.pop();
        for(int i=0; i<6; i++){
            if(!v[go[i].first] || v[go[i].second] == bot[go[i].second]) continue;
            vector<int> k = sw(v,go[i].first,go[i].second);
            if(!check[k[0]][k[1]][k[2]]){
                check[k[0]][k[1]][k[2]] = 1;
                q.push(k);
            }
        }
    }
    for(int i=0; i<=200; i++) for(int j=0; j<=200; j++) if(check[0][i][j]) ans.push_back(j);
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(int i : ans) cout<<i<<' ';
}

#include <bits/stdc++.h>

using namespace std;
int arr[10][10];
vector<pair<int,int> > pos;
void end(){
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++) cout<<arr[i][j]<<' ';
        cout<<'\n';
    }
    exit(0);
}
void dfs(int idx){
    if(idx == pos.size()) end();
    int px_y = pos[idx].first-1;
    int px_x = pos[idx].second-1;
    px_y/=3;px_x/=3;
    vector<int> go;
    bool check[10]={false,};
    for(int i=px_y*3+1; i<=px_y*3+3; i++){
        for(int j=px_x*3+1; j<=px_x*3+3; j++){
            check[arr[i][j]]=1;
        }
    }
    for(int i=1; i<=9; i++) check[arr[pos[idx].first][i]]=1;
    for(int i=1; i<=9; i++) check[arr[i][pos[idx].second]]=1;
    for(int i=1; i<=9; i++) if(!check[i]) go.push_back(i);
    for(int i=0; i<go.size(); i++){
        arr[pos[idx].first][pos[idx].second] = go[i];
        dfs(idx+1);
        arr[pos[idx].first][pos[idx].second] = 0;
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(nullptr);
    for(int i=1; i<=9; i++) for(int j=1; j<=9; j++){
        cin>>arr[i][j];
        if(arr[i][j] == 0) pos.push_back({i,j});
    }
    dfs(0);
}

#include <bits/stdc++.h>

using namespace std;
bool paper[11][11];
vector<pair<int,int> > pos;
int ans = 1e9,can[6];
bool in(int a,int b){return 1<=a && a<=10 && 1<=b && b<=10;}
bool sizek(int y,int x,int k){
    k--;
    if(!in(y+k,x+k) || can[k+1] > 4) return false;
    for(int i=y; i<=y+k; i++) for(int j=x; j<=x+k; j++) if(!paper[i][j]) return false;
    return true;
}
void rvs(int y,int x,int k){
    k--;
    for(int i=y; i<=y+k; i++) for(int j=x; j<=x+k; j++) paper[i][j] = false;
}
void out(int y,int x,int k){
    k--;
    for(int i=y; i<=y+k; i++) for(int j=x; j<=x+k; j++) paper[i][j] = true;
}
bool end_game(){
    for(int i=1; i<=10; i++) for(int j=1; j<=10; j++) if(paper[i][j]) return false;
    ans = min(ans,can[1]+can[2]+can[3]+can[4]+can[5]);
    return true;
}
void go(int idx){
    if(end_game()) return;
    auto[here_y,here_x] = pos[idx];
    int index = 0;
    while(!paper[here_y][here_x]){
        here_y = pos[index].first;
        here_x = pos[index].second;
        index++;
    }
    for(int i=1; i<=5; i++){
        if(sizek(here_y,here_x,i)){
            rvs(here_y,here_x,i);
            can[i]++;
            go(idx+1);
            can[i]--;
            out(here_y,here_x,i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    for(int i=1; i<=10; i++) for(int j=1; j<=10; j++){
        cin>>paper[i][j];
        if(paper[i][j]) pos.push_back({i,j});
    }
    go(0);
    ans==1e9 ? cout<<-1 : cout<<ans;
}

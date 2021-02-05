#include <bits/stdc++.h>

using namespace std;
int n,dx[4]={1,-1,-1,1},dy[4]={-1,1,-1,1},ans;
bool arr[16][16];
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=n;}
bool can(int y,int x){
    for(int i=1; i<=n; i++) if(arr[y][i] || arr[i][x]) return false;
    for(int i=0; i<4; i++){
        int here_y = y,here_x = x;
        while(in(here_y,here_x)){
            if(arr[here_y][here_x]) return false;
            here_y += dy[i];
            here_x += dx[i];
        }
    }
    return true;
}
void go(int height){
    if(height == n){
        ans++;
        return;
    }
    for(int i=1; i<=n; i++){
        if(can(height+1,i)){
            arr[height+1][i] = true;
            go(height+1);
            arr[height+1][i] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    go(0);
    cout<<ans<<'\n';
}
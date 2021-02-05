#include <bits/stdc++.h>

using namespace std;
int n,board[20][20],temp[20][20],ans = 1e9,dx[5]={0,-1,0,1,0},dy[5]={-1,0,1,0,0};
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=n;}
void turn(int a,int b){
    for(int i=0; i<5; i++){
        int next_y = a + dy[i];
        int next_x = b + dx[i];
        if(in(next_y,next_x)) temp[next_y][next_x] = temp[next_y][next_x] ? 0 : 1;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>board[i][j];
    for(int i=0; i<=(1<<n)-1; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++) for(int k=1; k<=n; k++) temp[j][k] = board[j][k];
        for(int j=1; j<=n; j++){
            if(i&(1<<(j-1))){
                cnt++;
                turn(1,j);
            }
        }
        for(int j=2; j<=n; j++) for(int k=1; k<=n; k++) if(temp[j-1][k]) turn(j,k),cnt++;
        bool go = true;
        for(int j=1; j<=n; j++) if(temp[n][j]) go = false;
        if(go) ans = min(cnt,ans);
    }
    cout<<(ans == 1e9 ? -1 : ans);
}
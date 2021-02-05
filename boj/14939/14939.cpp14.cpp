#include <bits/stdc++.h>

using namespace std;
int board[11][11],temp[11][11],ans=1e9,dx[5]={0,-1,0,1,0},dy[5]={1,0,-1,0,0},cnt;
bool in(int a,int b){return 1<=a && a<=10 && 1<=b && b<=10;}
void turn(int a,int b){
    for(int i=0; i<5; i++){
        int next_x = b+dx[i];
        int next_y = a+dy[i];
        if(in(next_y,next_x)) temp[next_y][next_x] = !temp[next_y][next_x];
    } cnt++;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    for(int i=1; i<=10; i++) for(int j=1; j<=10; j++){
        char c;
        cin>>c;
        if(c=='O') board[i][j] = 1;
    }
    for(int i=0; i<=(1<<10)-1; i++){
        cnt = 0;
        for(int j=1; j<=10; j++) for(int k=1; k<=10; k++) temp[j][k] = board[j][k];
        for(int j=1; j<=10; j++) if(i & (1<<(j-1))) turn(1,j);
        for(int j=2; j<=10; j++) for(int k=1; k<=10; k++) if(temp[j-1][k]) turn(j,k);
        bool go = true;
        for(int j=1; j<=10; j++) if(temp[10][j]) go = false;
        if(go) ans = min(ans,cnt);
    }
    cout<<(ans == 1e9 ? -1 : ans);
}
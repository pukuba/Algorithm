#include <bits/stdc++.h>

using namespace std;
set<string> check;
int _map[11][11],dx[4]={0,-1,0,1},dy[4]={1,0,-1,0},cnt;
char turn(int a){return '0'+a;}
bool in(int a,int b){return 1<=a && a<=5 && 1<=b && b<=5;}
void gogo(int y,int x,string k,int go){
    if(go == 7){
        if(check.count(k)) return;
        check.insert(k);
        cnt++;
        return;
    }
    for(int i=0; i<4; i++){
        int next_x = dx[i] + x;
        int next_y = dy[i] + y;
        if(!in(next_y,next_x)) continue;
        gogo(next_y,next_x,k+turn(_map[y][x]),go+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    for(int i=1; i<=5; i++) for(int j=1; j<=5; j++) cin>>_map[i][j];
    for(int i=1; i<=5; i++) for(int j=1; j<=5; j++) gogo(i,j,"",1);
    cout<<cnt;
}
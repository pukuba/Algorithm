#include <bits/stdc++.h>

using namespace std;
int a,b,n,m,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
struct robot{
    int y,x,look;
};
vector<robot> v;
void check(int y,int x,int num){
    num--;
    for(int i=0; i<v.size(); i++){
        if(i == num) continue;
        if(v[i].y == y && v[i].x == x){
            cout<<"Robot "<<num+1<<" crashes into robot "<<i+1<<'\n';
            exit(0);
        }
    }
}
void in(int y,int x,int c){
    if(!(1<=y && y<=a && 1<=x && x<=b)){
        //Robot 1 crashes into the wall
        cout<<"Robot "<<c<<" crashes into the wall"<<'\n';
        exit(0);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>b>>a>>n>>m;
    for(int i=1; i<=n; i++){
        int y,x,l;
        char look;
        cin>>x>>y>>look;
        if(look == 'E') l = 1;
        if(look == 'N') l = 0;
        if(look == 'S') l = 2;
        if(look == 'W') l = 3;
        v.push_back({y,x,l});
    }
    for(int i=1; i<=m; i++){
        int rb, t;
        char c;
        cin>>rb>>c>>t;
        if(c == 'R') v[rb-1].look += t;
        if(c == 'L') v[rb-1].look += t * 3;
        if(c == 'F'){
            int k = v[rb-1].look % 4;
            for(int j=1; j<=t; j++){
                v[rb-1].x += dx[k];
                v[rb-1].y += dy[k];
                check(v[rb-1].y,v[rb-1].x,rb);
            }
        }
        in(v[rb-1].y,v[rb-1].x,rb);
    }
    cout<<"OK";
}
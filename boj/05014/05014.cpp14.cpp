#include <bits/stdc++.h>

using namespace std;
struct Point{
    int x,rank;
};
bool check[1000001];
int F,S,G,U,D;
int in(int a){
    return (1<=a && a<=F);
}
int main(){
    memset(check,false,sizeof(check));
    cin>>F>>S>>G>>U>>D;
    int dx[2]={U,-D};
    queue<Point> q;
    q.push({S,0});
    check[S]=true;
    while(!q.empty()){
        int cur_x=q.front().x;
        int cur_rank=q.front().rank;
        q.pop();
        if(cur_x==G){
            cout<<cur_rank;
            return 0;
        }
        for(int i=0; i<2; i++){
            int next_x=cur_x+dx[i];
            int next_rank=cur_rank+1;
            if(in(next_x) && check[next_x]==false){
                check[next_x]=true;
                q.push({next_x,next_rank});
            }
        }
    }
    cout<<"use the stairs";
    return 0;
}

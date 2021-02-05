#include <iostream>
#include <queue>

using namespace std;
bool check[100001];
struct point{
    int x,time;
};
int in(int a){
    return (0<=a && a<=100000);
}
int main(){
    int n,m;
    cin>>n>>m;
    if(n==m){
        cout<<0;
        return 0;
    }
    queue<point> q;
    q.push({n,0});
    check[n]=true;
    while(!q.empty()){
        int cur_x=q.front().x;
        int cur_time=q.front().time;
        q.pop();
        if(cur_x==m){
            cout<<cur_time;
            return 0;
        }
        if(in(cur_x*2) && check[cur_x*2]==false){
            check[cur_x*2]=true;
            q.push({cur_x*2,cur_time+1});
        }
        if(in(cur_x+1) && check[cur_x+1]==false){
            check[cur_x+1]=true;
            q.push({cur_x+1,cur_time+1});
        }
        if(in(cur_x-1) && check[cur_x-1]==false){
            check[cur_x-1]=true;
            q.push({cur_x-1,cur_time+1});
        }
    }
}

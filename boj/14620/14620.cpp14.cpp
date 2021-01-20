#include <bits/stdc++.h>

using namespace std;
int n,arr[11][11],ans=1e9,dx[5]={0,1,0,-1,0},dy[5]={0,0,-1,0,1};
using pi = pair<int,int>;
vector<pi> v;
bool in(int a,int b){return 1<=a && a<=n && 1<=b && b<=n;}
int can(pi a,pi b,pi c){
    int ret = 0;
    set<pi> s;
    for(int i=0; i<5; i++){
        int ay = dy[i] + a.first, ax = dx[i] + a.second;
        int by = dy[i] + b.first, bx = dx[i] + b.second;
        int cy = dy[i] + c.first, cx = dx[i] + c.second;
        if(!in(ay,ax) || !in(by,bx) || !in(cy,cx)){
            return -1;
        }
        if(s.count({ay,ax}) || s.count({by,bx}) || s.count({cy,cx})) return -1;
        s.insert({ay,ax}); s.insert({by,bx}); s.insert({cy,cx});
        ret += arr[ay][ax] + arr[by][bx] + arr[cy][cx];
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
            v.push_back({i,j});
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            for(int k=j+1; k<v.size(); k++){
                pi a = v[i], b = v[j], c = v[k];
                int check = can(a,b,c);
                if(check >= 0){
                    ans = min(ans,check);
                }
            }
        }
    }
    cout<<ans;
}

#include <bits/stdc++.h>

using namespace std;
struct pos{
    int y,x,t;
    bool operator < (const pos &a) const {
        if(y == a.y){
            if(x == a.x) return t < a.t;
            return x < a.x;
        }
        return y < a.y;
    }
};
int n,m,k,arr[55][55],temp[55][55],temp2[55][55],ans=1e9;
vector<pos> v;
bool check(int ly,int lx,int ry,int rx){
    return ry - ly > 0 && rx - lx > 0;
}
void loop(int ly,int lx,int ry,int rx){
    for(int i=lx+1; i<=rx; i++) temp2[ly][i] = temp[ly][i-1];
    for(int i=ly+1; i<=ry; i++) temp2[i][rx] = temp[i-1][rx];
    for(int i=rx-1; i>=lx; i--) temp2[ry][i] = temp[ry][i+1];
    for(int i=ry-1; i>=ly; i--) temp2[i][lx] = temp[i+1][lx];
    
    for(int i=lx; i<=rx; i++) temp[ly][i] = temp2[ly][i];
    for(int i=ly; i<=ry; i++) temp[i][rx] = temp2[i][rx];
    for(int i=rx; i>=lx; i--) temp[ry][i] = temp2[ry][i];
    for(int i=ry; i>=ly; i--) temp[i][lx] = temp2[i][lx];
}
void rotate(int y,int x,int r){
    int ly = y-r, lx = x-r, ry = y+r, rx = x+r;
    while(check(ly,lx,ry,rx)){
        loop(ly,lx,ry,rx);
        ly++;
        lx++;
        ry--;
        rx--;
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1,x,y,z; i<=k; i++){
        cin>>y>>x>>z;
        v.push_back({y,x,z});
    }
    sort(v.begin(),v.end());
    do{
        for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) temp[i][j] = arr[i][j];
        
        for(pos i : v){
            rotate(i.y,i.x,i.t);
        }
        for(int i=1; i<=n; i++){
            int tmp = 0;
            for(int j=1; j<=m; j++){
                tmp += temp[i][j];
            }
            ans = min(tmp,ans);
        }
    }while(next_permutation(v.begin(), v.end()));
    cout<<ans<<'\n';
}

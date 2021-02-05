#include <bits/stdc++.h>

using namespace std;
int n,m,ans;
struct pos{
    int x,idx,real;
    bool operator < (const pos & a) const {
        return a.x < x;
    }
};
vector<pos> v[103];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        int x;
        cin>>x;
        v[i].push_back({x,j,0});
    }
    for(int i=1; i<=n; i++) sort(v[i].begin(),v[i].end());
    for(int i=1; i<=n; i++){
        int pv = v[i][0].x,k=1,rank=1;
        if(v[i].size() == 1) v[i][0].real = 1;
        else{
            for(int j=1; j<m; j++){
                if(v[i][j].x != pv || j == m-1){
                    for(int kk=j-k; kk<j; kk++) v[i][kk].real = rank;
                    k=1;
                    rank++;
                    pv = v[i][j].x;
                }
                else rank++,k++;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            bool can = 1;
            for(int k = 0; k<v[i].size(); k++){
                if(v[i][k].real != v[j][k].real || v[i][k].idx != v[j][k].idx){
                    can = 0;
                    break;
                }
            }
            if(can) ans++;
        }
    }
    
    cout<<ans<<'\n';
}
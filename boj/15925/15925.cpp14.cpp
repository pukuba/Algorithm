#include <bits/stdc++.h>

using namespace std;
int n,m,_map[33][33],temp[33][33];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>_map[i][j];
    while(1){
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) temp[i][j] = _map[i][j];
        bool f = true;
        for(int i=1; i<=n; i++){
            int cnt1 = 0,cnt2 = 0;
            for(int j=1; j<=n; j++){
                if(_map[i][j] == m) cnt1++;
                if(_map[j][i] == m) cnt2++;
            }
            for(int j=1; j<=n; j++){
                if(cnt1 > n/2) _map[i][j] = m;
                if(cnt2 > n/2) _map[j][i] = m;
            }
        }
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(temp[i][j] != _map[i][j]) f = false;
        if(f) break;
    }
    bool ans = true;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) if(_map[i][j] != m) ans = false;
    if(!ans) cout<<0;
    else cout<<1;
}
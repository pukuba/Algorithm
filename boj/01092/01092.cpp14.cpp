#include <bits/stdc++.h>

using namespace std;
vector<int> v[55],k;
int n,m,a[55],b[10003],ans;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i=1; i<=m; i++){
        cin>>b[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+m,cmp);
    for(int i=1; i<=m; i++){
        pair<int,int> canidx = {-1,-1};
        for(int j=1; j<=n; j++){
            if(b[i] <= a[j]){
                if(canidx.first == -1){
                    canidx = {j,v[j].size()};
                }
                else{
                    if(canidx.second > v[j].size()){
                        canidx = {j,v[j].size()};
                    }
                }
            }
        }
        if(canidx.first == -1) {
            cout<<-1<<'\n';
            return 0;
        }
        v[canidx.first].push_back(i);
    }
    for(int i=1; i<=n; i++){
        ans = ans > v[i].size() ? ans : v[i].size();
    }
    cout<<ans<<'\n';
}

#include <bits/stdc++.h>

using namespace std;
int n,m;
vector<pair<int,int> > a;
int query(int fir,int sec,int res){
    int cnt=0;
    for(int i=0; i<n; i++){
        if(a[i].second>=fir && a[i].second<=sec){
            cnt++;
            if(cnt == res){
                return a[i].first;
            }
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        a.push_back({x,i});
    }
    sort(a.begin(),a.end());
    for(int i=0; i<m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        cout << query(x,y,z) <<'\n';
    }
}

#include <bits/stdc++.h>

using namespace std;
int n,m,arr[1000001],temp,ans;
vector<pair<int,int> >v;
void _copy(int from,int to){
    for(int i=to; i>=from; i--){
        if(arr[i] == arr[from]) return;
        arr[i] = arr[from];
    }
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n; i++) arr[i] = i;
    for(int i=1; i<=m; i++){
        int from,to;
        cin>>from>>to;
        v.push_back({from,to});
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++) if(arr[v[i].first] != arr[v[i].second]) _copy(v[i].first,v[i].second);
    for(int i=1; i<=n; i++){
        if(temp != arr[i]){
            ans++;
            temp = arr[i];
        }
    }
    cout<<ans;
}

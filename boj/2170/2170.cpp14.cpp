#include <bits/stdc++.h>

using namespace std;
int n;
struct point{
    int from,to,cnt;
}ans;
vector<pair<int,int>> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        if(!i){
            ans.from=v[i].first;
            ans.to=v[i].second;
            ans.cnt+=v[i].second-v[i].first;
        }
        else{
            if(ans.from<=v[i].first && ans.to>=v[i].second) continue;
            else if(ans.to<= v[i].first ){
                ans.cnt+=v[i].second-v[i].first;
                ans.to=v[i].second;
                ans.from=v[i].first;
            }
            else if(ans.from <= v[i].first && ans.to < v[i].second){
                ans.cnt+=v[i].second-ans.to;
                ans.to=v[i].second;
            }
        }
    }
    cout<<ans.cnt<<'\n';
}

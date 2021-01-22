#include <bits/stdc++.h>

using namespace std;
int n;
priority_queue<int, vector<int>, greater<int>> pq;
int main(){
    int ans=0;
    cin>>n;
    vector<pair<int,int> > v(n);
    for(int i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++){
        pq.push(v[i].second);
        ans+=v[i].second;
        if(pq.size()>v[i].first){
            ans-=pq.top();
            pq.pop();
        }
    }
    cout<<ans<<'\n';
}

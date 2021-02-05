#include <bits/stdc++.h>

using namespace std;
int n,x;
vector<int> v,w;
void pick(int idx){
    if(w.size() == 6){
        for(int i : w) cout<<i<<' ';
        cout<<'\n';
        return;
    }
    for(int i=idx; i<n; i++){
        w.push_back(v[i]);
        pick(i+1);
        w.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    while(1){
        cin>>n;
        if(!n) break;
        v.clear();
        for(int i=1;i<=n;i++) cin>>x,v.push_back(x);
        pick(0);
        cout<<'\n';
    }
}
#include <bits/stdc++.h>

using namespace std;
int n,tree[2222222],MAX = 5e5,mxn;
pair<int,int> p[101010];
stack<int> ret;
int add(int node,int s,int e,int pos,int diff){
    if(s > pos || e < pos) return tree[node];
    if(s == e) return tree[node] = diff;
    return tree[node] = max(add(node*2,s,s+e>>1,pos,diff),add(node*2+1,(s+e>>1)+1,e,pos,diff));
}
int qry(int node,int s,int e,int l,int r){
    if(s > r || e < l) return 0;
    if(l <= s && e <= r) return tree[node];
    return max(qry(node*2,s,s+e>>1,l,r),qry(node*2+1,(s+e>>1)+1,e,l,r));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n);
    // lis가 안되는 left출력해야함!!!
    for(int i=1; i<=n; i++){
        int cnt = qry(1,1,MAX,1,p[i].second-1) + 1;
        add(1,1,MAX,p[i].second,cnt);
    }
    int ans = qry(1,1,MAX,1,MAX);
    cout<<n-ans<<'\n';
    for(int i=n; i>=1; i--){
        if(qry(1,1,MAX,p[i].second,p[i].second) == ans) ans--;
        else ret.push(p[i].first);
    }
    while(ret.size()){
        cout<<ret.top()<<'\n';
        ret.pop();
    }
}
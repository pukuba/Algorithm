#include <bits/stdc++.h>

using namespace std;
vector<int> idx;
int getidx(int x){return lower_bound(idx.begin(), idx.end(), x) - idx.begin();}
int n,a[1010101],tree[4444444],mxn=1000005,lis[1010101];
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
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    idx.resize(n);
    for(int i=1; i<=n; i++){
        cin>>a[i];
        idx[i-1] = a[i];
    }
    sort(idx.begin(),idx.end());
    idx.erase(unique(idx.begin(),idx.end()),idx.end());
    for(int i=1; i<=n; i++) a[i] = getidx(a[i]) + 3;
    for(int i=1; i<=n; i++){
        int cnt = qry(1,1,mxn,1,a[i]-1) + 1;
        lis[i] = cnt;
        add(1,1,mxn,a[i],cnt);
    }
    stack<int> stk;
    int ans = qry(1,1,mxn,1,mxn);
    cout<<ans<<'\n';
    for(int i=n; i>=1; i--){
        if(!ans) break;
        if(lis[i] == ans){
            ans--;
            stk.push(a[i]);
        }
    }
    while(stk.size()){
        cout<<idx[stk.top()-3]<<" ";
        stk.pop();
    }
}
#include <bits/stdc++.h>

using namespace std;
int n,b,k,t[111111],x,tree[2222222],ans;
int init(int node,int start,int end){
    if(start==end) return tree[node] = t[start];
    return tree[node] = init(node*2,start,start+end>>1) + init(node*2+1,(start+end>>1)+1,end);
}
int sum(int node,int start,int end,int left,int right){
    if(start > right || end < left) return 0;
    if(left <= start  && end <= right) return tree[node];
    return sum(node*2,start,start+end>>1,left,right) + sum(node*2+1,(start+end>>1)+1,end,left,right);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>k>>b;
    for(int i=1; i<=n; i++) t[i] = 1;
    for(int i=1; i<=b; i++){
        cin>>x;
        t[x] = 0;
    }
    init(1,1,n);
    for(int i=1; i<=n; i++){
        ans = max(ans,sum(1,1,n,i,i+k-1));
    }
    cout<<k-ans;
}
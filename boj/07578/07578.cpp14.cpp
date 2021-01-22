#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,a[1111111],x,tree[2222222],b[1111111],ans;
ll update(int node,int start,int end,int pos){
    if(start > pos || end < pos) return 0;
    if(pos <= start && end <= pos) return tree[node] = 1;
    update(node*2,start,start+end>>1,pos);
    update(node*2+1,(start+end>>1)+1,end,pos);
    return tree[node] = tree[node*2] + tree[node*2+1];
}
ll sum(int node,int start,int end,int left,int right){
    if(right < start || end < left) return 0;
    if(left <= start && end <= right) return tree[node];
    return sum(node*2,start,start+end>>1,left,right) + sum(node*2+1,(start+end>>1)+1,end,left,right);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++){
        cin>>x;
        b[x]=i;
    }
    for(int i=1; i<=n; i++){
        ans += sum(1,1,n,b[a[i]],n);
        update(1,1,n,b[a[i]]);
    }
    cout<<ans;
}
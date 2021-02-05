#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll tree[2222222],n,inf=1e9,ans;
struct point{
    int a,b,c;
    bool operator < (const point &s) const{
        return a<s.a;
    }
};
point arr[511111];
void update(int node,int start,int end,int pos,int value){
    if(start > pos || end < pos) return;
    if(pos <= start && end <=pos){
        tree[node]=value;
        return;
    }
    update(node*2,start,start+end>>1,pos,value);
    update(node*2+1,(start+end>>1)+1,end,pos,value);
    tree[node] = min(tree[node*2],tree[node*2+1]);
}
ll query(int node,int start,int end,int left,int right){
    if(start > right || end < left) return inf;
    if(left <= start && end <= right) return tree[node];
    return min(query(node*2,start,start+end>>1,left,right),query(node*2+1,(start+end>>1)+1,end,left,right));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=3; i++) for(int j=1; j<=n; j++){
        int x;
        cin>>x;
        if(i==1) arr[x].a=j;
        if(i==2) arr[x].b=j;
        if(i==3) arr[x].c=j;
    }
    sort(arr+1,arr+n+1);
    for(int i=1; i<=n; i++) update(1,1,n,i,inf);
    for(int i=1; i<=n; i++){
        if(query(1,1,n,1,arr[i].b) > arr[i].c) ans++;
        update(1,1,n,arr[i].b,arr[i].c);
    }
    cout<<ans<<'\n';
}

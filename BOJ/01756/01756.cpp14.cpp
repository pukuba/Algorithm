#include <bits/stdc++.h>

using namespace std;
int n,m,a[333333],pz[333333],tree[1222222],line,temp,last,check_mid;
int init(int node,int start,int end){
    if(start == end) return tree[node] = a[start];
    return tree[node] = min(init(node<<1,start,start+end>>1),init((node<<1)+1,(start+end>>1)+1,end));
}
int query(int node,int start,int end,int left,int right){
    if(start > right || end < left) return 2e9;
    if(left <= start && end <= right) return tree[node];
    return min(query(node<<1,start,start+end>>1,left,right),query((node<<1)+1,(start+end>>1)+1,end,left,right));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    //freopen("/Users/erolf0123/Downloads/oi13_1t/kra/kra3b.in","r",stdin);
    cin>>n>>m;
    line = n;
    for(int i=1; i<=n; i++) cin>>a[i];
    init(1,1,n);
    for(int i=1; i<=m; i++){
        cin>>pz[i];
        int _min = query(1,1,n,1,line);
        if(_min >= pz[i]){
            last = line;
            line--;
            temp++;
        }
        else{
            int mid = line>>1;
            int from = 1, to = line;
            while(from<to){
                if(mid == check_mid) break;
                check_mid = mid;
                int left = query(1,1,n,from,mid); // 5
                int right = query(1,1,n,mid,to); // 5
                if(left < pz[i]){
                    to = mid;
                    mid = from + to >> 1;
                    continue;
                }
                else{
                    from = mid;
                    mid = from + to >>1;
                }
            }
            if(a[mid] < pz[i]) break;
            last = mid;
            line = mid-1;
            temp++;
        }
    }
    if(temp == m && n >= m && last > 0) cout<<last;
    else cout<<0;
}
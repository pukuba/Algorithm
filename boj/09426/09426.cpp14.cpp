#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll tree[65536*3],n,k,a;
queue<int> q;
void update(int x,int v){
    for(; x<=65536*2; x+=x&-x) tree[x] += v;
}
int sum(int x){
    ll ret = 0;
    for(; x>0; x-=x&-x) ret += tree[x];
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=1,x; i<=n; i++){
        cin>>x;
        update(++x,1);
        q.push(x);
        if(i >= k){
            int s=1, e=65537,ans=-1;
            while(s<=e){
                int mid = s+e>>1;
                ll tmp = sum(mid);
                if(tmp >= (k+1)/2){
                    ans = mid;
                    e = mid - 1;
                }
                else if(tmp < (k+1)/2){
                    s = mid + 1;
                }
            }
            a += --ans;
            update(q.front(),-1);
            q.pop();
        }
    }
    cout<<a<<'\n';
}
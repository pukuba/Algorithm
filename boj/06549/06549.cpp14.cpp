#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,d[100001];
ll divi(int s,int e){
    if(s == e) return 0;
    if(s+1 == e) return d[s];
    ll mid = (s+e)/2,ret = max(divi(s,mid),divi(mid,e));
    ll w = 1, h = d[mid], l = mid, r = mid;
    while(r-l+1 < e-s){
        int left_go=-1,right_go=-1;
        if(s<l) left_go = min(h,d[l-1]);
        if(r<e-1) right_go = min(h,d[r+1]);
        if(left_go >= right_go){
            h = left_go;
            l--;
        }
        else{
            h = right_go;
            r++;
        }
        ret = max(ret,++w*h);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    while(1){
        cin>>n;
        if(!n) return 0;
        memset(d,false,sizeof(d));
        for(int i=1; i<=n; i++) cin>>d[i];
        cout<<divi(1,n+1)<<'\n';
    }
}

#include <bits/stdc++.h>

using namespace std;
int d[100001],n;
int divi(int s,int e){
    if(s==e) return 0;
    if(s+1 == e) return d[s];
    int mid = (s+e)/2,ret = max(divi(s,mid),divi(mid,e));
    int l=mid,r=mid,h=d[mid],w=1;
    while(r-l+1 < e-s){
        int left_go = -1, right_go = -1;
        if(s<l) left_go = min(h,d[l-1]);
        if(r<e-1) right_go = min(h,d[r+1]);
        if(left_go >= right_go){
            l--;
            h=left_go;
        }
        else{
            r++;
            h=right_go;
        }

        ret = max(ret,++w*h);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++) cin>>d[i];
    cout<<divi(1,n+1)<<'\n';
}

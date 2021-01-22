#include <bits/stdc++.h>

using namespace std;
long long n,d[100001];
long long dvid(int s,int e){
    if(s==e) return 0;
    if(s+1==e) return d[s]*d[s];
    long long mid = (s+e)/2;
    long long ret = max(dvid(s,mid),dvid(mid,e));
    long long l =mid,r = mid,_min=d[mid],sum=d[mid];
    while(r-l+1 < e-s){
        int left_go = -1,right_go = -1;
        if(s<l) left_go = d[l-1];
        if(r<e-1) right_go = d[r+1];
        if(left_go>=right_go){
            l--;
            _min = min(_min,d[l]);
            sum+=d[l];
        }
        else{
            r++;
            _min = min(_min,d[r]);
            sum+=d[r];
        }
        ret = max(ret, _min*sum);
    }
    return ret;
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>d[i];
    cout<<dvid(1,n+1);
}

#include <bits/stdc++.h>

using namespace std;
int n,a[1005],d[1005],cnt,ans = 1,idx,_prev[1005];
stack<int> s;
void go(int idx){
    if(idx == -1) return;
    go(_prev[idx]);
    cout << a[idx] << " ";
    return;
}
int main(){
    cin>>n;
    fill(d,d+1005,1);
    fill(_prev, _prev + 1005, -1);
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            if(a[j]<a[i] && d[j]+1 > d[i]){
                d[i]=d[j]+1;
                _prev[i]=j;
                if(ans < d[i]){
                    idx = i; ans = d[i];
                }
            }
        }
    }
    cout<<ans<<'\n';
    if(ans==1){
        cout<<a[1]<<'\n';
        return 0;
    }
    go(idx);
}

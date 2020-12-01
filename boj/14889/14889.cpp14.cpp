#include <bits/stdc++.h>

using namespace std;
int n,arr[22][22],ans=1e9;
bool use[22];
void check(){
    int ret1=0,ret2=0;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(use[i] && use[j]) ret1+=arr[i][j] + arr[j][i];
            if(!use[i] && !use[j]) ret2+=arr[i][j] + arr[j][i];
        }
    }
    ans = min(ans,abs(ret1-ret2));
}
void go(int pick,int idx){
    if(idx > n) return;
    if(pick == n/2){
        check();
        return;
    }
    use[idx+1] = true;
    go(pick+1,idx+1);
    use[idx+1] = false;
    go(pick,idx+1);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n;
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) cin>>arr[i][j];
    go(0,0);
    cout<<ans;
}
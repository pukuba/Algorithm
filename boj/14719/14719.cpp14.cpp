#include <iostream>

using namespace std;
int n,m,arr[505],ans;
bool lgo(int cnt,int x){
    if(!x) return 0;
    if(arr[x] >= cnt) return 1;
    return lgo(cnt,x-1);
}
bool rgo(int cnt,int x){
    if(x == m+1) return 0;
    if(arr[x] >= cnt) return 1;
    return rgo(cnt,x+1);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++) cin>>arr[i];
    for(int i=1; i<=n; i++){
        for(int j=2; j<m; j++){
            if(arr[j] < i){
                if(lgo(i,j) && rgo(i,j)){
                    ans++;
                    //cout<<i<<' '<<j<<'\n';
                }
            }
        }
    }
    cout<<ans<<'\n';
}
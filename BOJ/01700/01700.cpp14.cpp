#include <bits/stdc++.h>

using namespace std;
int n,m,arr[111],plug[111],ans,lazy[111];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=m; i++) cin>>arr[i];
    for(int i=1; i<=m; i++){
        memset(lazy,0,sizeof(lazy));
        bool check = false;
        for(int j=1; j<=n; j++) if(plug[j] == arr[i]) check = true;
        if(check) continue;
        for(int j=1; j<=n; j++){
            if(!plug[j]) plug[j] = arr[i],check = true;
            if(check) break;
        }
        if(check) continue;
        for(int j=1; j<=n; j++) for(int k=i+1; k<=m; k++) if(arr[k] == plug[j] && !lazy[j]) lazy[j]=k;
        for(int j=1; j<=n; j++) if(lazy[j] == 0){
            plug[j] = arr[i],check = true;
            ans++;
            break;
        }
        if(check) continue;
        pair<int,int> max_index ={-1e9,-1e9};
        for(int j=1; j<=n; j++) if(max_index.first < lazy[j]) max_index = {lazy[j],j};
        plug[max_index.second] = arr[i];
        ans++;
    }
    cout<<ans;
}
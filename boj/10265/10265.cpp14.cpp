#include <bits/stdc++.h>

using namespace std;
int n,m,arr[1004],comp[1004],comp_size[1004],make_id,cycle_size,cycle[1004];
bool dp[1004],check[1004],finished[1004];
int dfs(int here,int id){
    check[here] = id;
    comp[here] = id;
    int graph_size = 1,next = arr[here];
    if(check[next]){
        if(!finished[next]){
            cycle_size=1;
            for(int i=next; i!=here; i=arr[i]) cycle_size++;
            cycle[id] = cycle_size;
        }
    } else graph_size += dfs(next,id);
    finished[here] = true;
    return graph_size;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>arr[i];
    for(int i=1; i<=n; i++){
        if(!check[i]){
            int next = arr[i];
            int id = comp[next];
            if(id){
                comp_size[id]++;
                comp[i] = id;
            }
            else{
                make_id++;
                comp_size[make_id] = dfs(i,make_id);
            }
        }
    }
    dp[0]=1;
    for(int i=1; i<=make_id; i++) for(int j=m; j>=1; j--) for(int k=cycle[i]; k<=comp_size[i]; k++) if(j-k >= 0) dp[j]|=dp[j-k];
    for(int i=m; i>=0; i--) if(dp[i]){
        cout<<i;
        return 0;
    }
}
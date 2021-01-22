#include <bits/stdc++.h>

using namespace std;
int n,m,k,ans1,ans;
vector<int> pass;
vector<vector<int> > v;
void dfs(int pick,int here){
    if(pick == m){
        v.push_back(pass);
        return;
    }
    for(int i=here+1; i<=n; i++){
        pass.push_back(i);
        dfs(pick+1,i);
        pass.pop_back();
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    dfs(0,0);
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size(); j++){
            int cnt = 0;
            for(int idx=0; idx<m; idx++) if(binary_search(v[j].begin(), v[j].end(),v[i][idx])) cnt++;
            if(cnt >= k) ans++;
        }
        ans1+=v.size();
    }
    printf("%.10lf",ans/(double)ans1);
}
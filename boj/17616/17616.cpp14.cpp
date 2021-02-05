#include <bits/stdc++.h>

using namespace std;
vector<int> v[1111111],v1[1111111];
#define pb(y,x) v[y].push_back(x),v1[x].push_back(y)
int a,b,c,ans1,ans2;
bool check[1111111];
void dfs1(int here){
    //cout<<here<<' ';
    check[here] = true;
    ans1++;
    for(int i: v[here]) if(!check[i]) dfs1(i);
}
void dfs2(int here){
    check[here]=true;
    ans2++;
    for(int i : v1[here]) if(!check[i]) dfs2(i);
}
int main(){
    cin>>a>>b>>c;
    for(int i=1; i<=b; i++){
        int x,y;
        cin>>x>>y;
        pb(x,y);
    }
    dfs1(c);
    memset(check,false,sizeof(check));
    dfs2(c);
    cout<<ans2<<' '<<a-ans1+1<<'\n';
}

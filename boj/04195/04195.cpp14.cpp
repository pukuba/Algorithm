#include <bits/stdc++.h>

using namespace std;
map<string,int> _map;
int root[500001],n,m,arr[5001],ttt;
bool check=true;
int find(int x){
    if(root[x]< 0) return x;
    return root[x]=find(root[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y){
        root[y]+=root[x];
        root[x]=y;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    while(n--){
        int x,cnt=0;
        cin>>x;
        memset(root,-1,sizeof(root));
        _map.clear();
        for(int i=1; i<=x; i++){
            string a,b;
            cin>>a>>b;
            if(_map[a] == 0){
                cnt++;
                _map[a] = cnt;
            }
            if(_map[b]==0){
                cnt++;
                _map[b]=cnt;
            }
            merge(_map[a], _map[b]);
            cout<<abs(root[find(_map[b])])<<'\n';
        }
    }
}
